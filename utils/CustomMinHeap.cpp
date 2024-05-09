//
// Created by oussama_ib0 on 5/6/24.
//

#include "CustomMinHeap.h"
#include "utils.h"

CustomMinHeap::CustomMinHeap(int _size) : size(_size), actual_size(-1) {
    container = new Node[size];
}

void CustomMinHeap::insert(char key, int value) {
    if (actual_size == size - 1) {
        // throw in a custom exception
        return;
    }

    actual_size++;
    container[actual_size] = Node(key, value);

    int current_index = actual_size;
    int parent_index = (current_index - 1) / 2;

    while (current_index > 0 && container[current_index].value < container[parent_index].value) {
        swap_node_array_element(container, parent_index, current_index);

        current_index = parent_index;
        parent_index = (current_index - 1) / 2;
    }
}

std::ostream& operator<<(std::ostream& out, const CustomMinHeap& customMinHeap) {
    for (int i = 0; i <= customMinHeap.actual_size; i++) {
        out << "Key: " << customMinHeap.container[i].key << ", Value: " << customMinHeap.container[i].value << std::endl;
    }
    return out;
}


