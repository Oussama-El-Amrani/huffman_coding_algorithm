cmake_minimum_required(VERSION 3.28)
project(huffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(huffman main.cpp
        Huffman.cpp
        Huffman.h
        utils/IntegerMinHeap.cpp
        utils/IntegerMinHeap.h
        utils/utils.cpp
        utils/utils.h
)
