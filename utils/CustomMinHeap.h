//
// Created by oussama_ib0 on 5/6/24.
//

#ifndef HUFFMAN_CUSTOMMINHEAP_H
#define HUFFMAN_CUSTOMMINHEAP_H


#include <ostream>

class CustomMinHeap {
public:
    struct Node {
        char key;
        int value;

        Node() : value('\0'), key(0) {}
        Node(char key, int value) : key(key), value(value) {};
    };
private:
    Node *container;
    int size;
    int actual_size;
public:
    CustomMinHeap(int _size);

    void  insert(char key, int value);

    friend std::ostream& operator<<(std::ostream& out, const CustomMinHeap& customMinHeap);

};


#endif //HUFFMAN_CUSTOMMINHEAP_H
