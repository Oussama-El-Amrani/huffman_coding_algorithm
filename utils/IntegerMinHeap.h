//
// Created by oussama_ib0 on 5/5/24.
//

#ifndef HUFFMAN_INTEGERMINHEAP_H
#define HUFFMAN_INTEGERMINHEAP_H

#include <iostream>
using namespace std;

class IntegerMinHeap {
private:
    int *container;
    int size;
    int actual_size;
public:
    IntegerMinHeap(int _size);

    void insert(int new_value);

    friend ostream& operator<< (ostream &out, IntegerMinHeap integerMinHeap);
};


#endif //HUFFMAN_INTEGERMINHEAP_H
