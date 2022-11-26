/*
    this library is a variation on the classic LZ77 algorithm.
    But instead of returning a 3 element tuple it returns 2 element tuple
    of length and position in case if a substring matches else zero and
    the character literal are returned.12 bits are used for the position
    while 4 bits are used for size. So a reference in total consumes 2 bytes
    of data.

    Currently it uses greedy parsing for searching the substrings for matches.
*/

#pragma once

//includes
#include <iostream>
#include <fstream>
#include <tuple>
#include <bitset>
#include <string>
#include <sys/stat.h>

#include "misc.hpp"

//magic numbers
//Buffer size and minimum sizes to consider while returning a reference.
#define SIZE_SB 4095
#define SIZE_LB 15
#define MIN_BYTE_COMPRESS 2

//flag/s
const char not_found_flag = '\0';

//prototypes
void compress(std::string inFilePath, std::string outFilePath);
void decompress(std::string inFilePath, std::string outFilePath);

