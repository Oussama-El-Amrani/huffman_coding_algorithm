//
// Created by oussama_ib0 on 5/6/24.
//

#ifndef HUFFMAN_CUSTOMMINHEAP_H
#define HUFFMAN_CUSTOMMINHEAP_H


#include <ostream>

struct CustomNode {
    char key;
    int value;
    CustomNode *left;
    CustomNode *right;

    CustomNode() : key('\0'), value(0), left(nullptr), right(nullptr) {}

    CustomNode(char k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class CustomMinHeap {
public:

private:
    CustomNode *container;
    int size;
public:
    int getActualSize() const;
    CustomNode *getRoot()const;
private:
    int actual_size;

    void heapifyDown();
public:
    CustomMinHeap(int _size);

    void insert(char key, int value);

    void insert(CustomNode *node);

    CustomNode *extract();

    friend std::ostream &operator<<(std::ostream &out, const CustomMinHeap &customMinHeap);

};


#endif //HUFFMAN_CUSTOMMINHEAP_H
