//
// Created by oussama_ib0 on 5/6/24.
//

#include "CustomMinHeap.h"
#include "utils.h"

CustomMinHeap::CustomMinHeap(int _size) : size(_size), actual_size(-1) {
    container = new CustomNode[size];
}

void CustomMinHeap::insert(char key, int value) {
    if (actual_size == size - 1) {
        throw std::out_of_range("Heap is empty");
    }

    actual_size++;
    container[actual_size] = CustomNode(key, value);

    int current_index = actual_size;
    int parent_index = (current_index - 1) / 2;

    while (current_index > 0 && container[current_index].value < container[parent_index].value) {
        swap_node_array_element(container, parent_index, current_index);

        current_index = parent_index;
        parent_index = (current_index - 1) / 2;
    }
}

void CustomMinHeap::insert(CustomNode *node) {
    if (actual_size == size - 1) {
        throw std::out_of_range("Heap is empty");
    }

    actual_size++;
    container[actual_size] = *node;

    int current_index = actual_size;
    int parent_index = (current_index - 1) / 2;

    while (current_index > 0 && container[current_index].value < container[parent_index].value) {
        swap_node_array_element(container, parent_index, current_index);

        current_index = parent_index;
        parent_index = (current_index - 1) / 2;
    }
}

std::ostream &operator<<(std::ostream &out, const CustomMinHeap &customMinHeap) {
    for (int i = 0; i <= customMinHeap.actual_size; i++) {
        out << "Key: " << customMinHeap.container[i].key << ", Value: " << customMinHeap.container[i].value
            << std::endl;
    }
    return out;
}

CustomNode *CustomMinHeap::extract() {
    if (actual_size == -1) {
        throw std::out_of_range("Heap is empty");
    }
    // get the root
    auto *root = new CustomNode(container[0].key, container[0].value);
    // extract the root from this heap
    container[0] = container[actual_size - 1];
    actual_size--;

    heapifyDown();

    return root;
}

void CustomMinHeap::heapifyDown() {
    int actual_root_index = 0;
    while (actual_root_index < actual_size) {
        // if the left or right child is smaller
        // than the actual root swap them
        int left_index = 2 * actual_root_index + 1;
        int right_index = 2 * actual_root_index + 2;
        int smallest_index = actual_root_index;

        if (left_index < actual_size && container[left_index].value < container[smallest_index].value) {
            smallest_index = left_index;
        }
        if (right_index < actual_size && container[right_index].value < container[smallest_index].value) {
            smallest_index = right_index;
        }

        if (smallest_index != actual_root_index) {
            swap_node_array_element(container, left_index, actual_root_index);
        } else {
            break;
        }
    }
}

int CustomMinHeap::getActualSize() const {
    return actual_size;
}

CustomNode *CustomMinHeap::getRoot() const {
    if (actual_size == -1) {
        throw std::out_of_range("Heap is empty");
    }


    return &container[0];
}



