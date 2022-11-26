#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

struct huff_node {
    char ch;
    int freq;
    string code;
    huff_node *left;
    huff_node *right;
    huff_node(){
        left = right = NULL;
    }
    huff_node(char c,int f=0){
        ch = c;
        freq = f;
    }
};

typedef huff_node *node_ptr;

class huffman {
    public:
        vector <node_ptr> node_array;

        fstream in_file, out_file;
        node_ptr root;
        char ch;
        string in_file_name, out_file_name;

        //functor
        class compare {
            public:
                bool operator()(const node_ptr& c1, const node_ptr& c2) const {
                    return c1->freq > c2->freq;
                }
        };

        priority_queue <node_ptr, vector<node_ptr>, compare> pq;

        void create_node_array();
        //traverse the huffman tree and get huffman code for a character
        void traverse(node_ptr, string);
        //convert a 8-bit 0/1 string of binary code to a decimal integer
        //so that direct binary bits are written to the output file.
        int binary_to_decimal(string);
        //convert a decimal integer to a 8-bit 0/1 string of binary code
        //to easily traverse the huffman tree.
        string decimal_to_binary(int);

        void build_tree(string&, char);
        void create_pq();
        void create_huffman_tree();
        void huffman_codes();
        void encoding_s();
        void decoding_s();
        void recreate_huffman_tree();
        huffman(string in_file_name, string out_file_name){
                this->in_file_name = in_file_name;
                this->out_file_name = out_file_name;
                create_node_array();
        }
};

#endif
