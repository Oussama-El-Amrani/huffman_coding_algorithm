//
// Created by oussama_ib0 on 4/26/24.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include <map>
#include "iostream"
#include "unordered_map"
#include "utils/IntegerMinHeap.h"
#include "utils/CustomMinHeap.h"

class Huffman {
private:
    std::string text;
    std::unordered_map<char, int> container_map;
    CustomMinHeap *min_heap;
    std::map<char, char> coding_map;

    void text_analyzer();
    void construct_min_heap();
public:
    // Todo: learn what is explicit in cpp
    explicit Huffman(std::string _text) : text(_text) {
        min_heap = new CustomMinHeap(_text.length());
    }

    void encoder();

    void decode();
};


#endif //HUFFMAN_HUFFMAN_H
