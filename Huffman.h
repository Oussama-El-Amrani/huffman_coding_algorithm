//
// Created by oussama_ib0 on 4/26/24.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include <map>
#include "iostream"
#include "unordered_map"

class Huffman {
private:
    std::string text;
    std::unordered_map<char, int> container_map;
    // already prototyped
    std::map<char, char> coding_map;
    void text_analyzer();
public:
    Huffman(std::string _text) : text(_text) {}
    void encoder();
    void decode();
};


#endif //HUFFMAN_HUFFMAN_H
