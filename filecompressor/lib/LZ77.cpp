#include "include/LZ77.hpp"

std::pair<uint16_t, uint8_t> longest_possible_substr(std::string &searchBuffer, std::string &lookaheadBuffer)
{

    uint16_t LOCAL_SB_SIZE = searchBuffer.size(), LOCAL_LB_SIZE = lookaheadBuffer.size();

    uint16_t global_best = 0, pos = 0;

    for (int i = LOCAL_SB_SIZE - 1; i >= 0; i--)
    {
        int local_best = 0;
        while (searchBuffer[i + local_best] == lookaheadBuffer[local_best] && local_best < LOCAL_LB_SIZE && (i + local_best) < LOCAL_SB_SIZE)
            local_best++;

        if (local_best > global_best)
        {
            global_best = local_best;
            pos = i;
        }
        if (global_best == LOCAL_LB_SIZE)
            break;
    }

    if (global_best < MIN_BYTE_COMPRESS)
        return (std::make_pair(0, 0));

    return (std::make_pair(LOCAL_SB_SIZE - pos, global_best));
}



void compress(std::string inFilePath, std::string outFilePath)
{
    std::ifstream inFile;
    inFile.open(inFilePath, std::ios::in | std::ios::binary);

    std::ofstream outFile;
    outFile.open(outFilePath, std::ios::binary | std::ios::out);

    if (!inFile)
    {
        std::cerr << "READ ERROR : Couldn't open file" << std::endl;
        exit(1);
    }

    if (!outFile)
    {
        std::cerr << "WRITE ERROR : Couldn't write file" << std::endl;
        exit(2);
    }

    //getting the input file size.
    unsigned long long inputSize = get_file_size(inFilePath), index= 0;

    //COPYING INPUT FILE CONTENT TO A TEMPORARY BUFFER
    std::string inputData = "";
    inputData.resize(inputSize);
    inFile.read(&inputData[0], inputSize);

    inFile.close();


    while (index < inputSize)
    {
        //declare the search buffera nd the look ahead buffer for the current index.
        std::string searchBuffer = index >= SIZE_SB ? inputData.substr(index - SIZE_SB, SIZE_SB) : inputData.substr(0, index);
        std::string lookAheadBuffer = inputData.substr(index, std::min((unsigned long long )SIZE_LB, inputSize - index));

        //store the result from the longest_possible_substr in a pair
        std::pair<uint16_t, uint8_t> match_tuple = longest_possible_substr(searchBuffer, lookAheadBuffer);

        
        //if there is no matching substring i.e. length=0 and size=0;
        if (match_tuple.second == 0)
        {
            //write the literal and the not found flag.
            outFile.write(&inputData[index],1);
            outFile.write(&not_found_flag,1);

            index++;
        }

        //matching substring is found 
        else
        {
            std::bitset<16> next_2_bytes(match_tuple.second << 12 | match_tuple.first);
            index += match_tuple.second;
            outFile.write(reinterpret_cast<const char *>(&next_2_bytes), 2);
        }
    }

    outFile.close();

}

void decompress(std::string inFilePath, std::string outFilePath)
{

    std::ifstream inFile;
    inFile.open(inFilePath, std::ios::binary | std::ios::in);

    if (!inFile)
    {
        std::cerr << "READ ERROR : Couldn't Open File !!!" << std::endl;
        exit(1);
    }


    char firstByte, secondByte;

    unsigned long long  index = 0;
    std::string outData = "";

    while (!inFile.eof())
    {
        inFile.get(firstByte);
        inFile.get(secondByte);
        if (inFile.eof())
            break;

        //\0 indiciates an empty byte i.e. a literal is in the byte after this one.
        if (secondByte == '\0') 
        {
            //add the literal to the buffer;
            outData += firstByte;
            index++;
        }

        // if a reference is found to some substring.
        else
        {     
            std::bitset<8> first(firstByte);

            //left shift the secondbyte 8 positions.
            std::bitset<16> referenceBytes(secondByte << 8);

            //copy the first byte into the reference byte.
            for (int i = 0; i < 8; i++)
                referenceBytes[i] = first[i];

            int length, size;

            //the first four bits give the size.
            size = (int)(referenceBytes >> 12).to_ulong();

            //then the remaining bits give the length.
            for (int i = 12; i < 16; i++){
                referenceBytes[i] = 0;
            }
            length = (int)referenceBytes.to_ulong();

            //copy "size" number of characters from "index-length" position.
            while (size--){
                outData += (outData[index - length]);
                index++;
            }
        }
    }

    inFile.close();


    //write the outData buffer to a file.
    std::ofstream outFile;
    outFile.open(outFilePath, std::ios::binary | std::ios::out);
    if (!outFile){
        std::cerr << "WRITE ERROR : Couldn't Open File !!!" << std::endl;
        exit(1);
    }

    outFile << outData;
    outFile.close();

}
