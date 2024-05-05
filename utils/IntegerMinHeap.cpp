//
// Created by oussama_ib0 on 5/5/24.
//

#include "IntegerMinHeap.h"
#include "utils.h"

IntegerMinHeap::IntegerMinHeap(int _size) : size(_size), actual_size(-1) {
    container = new int[size];
}

void IntegerMinHeap::insert(int new_value) {
    if (actual_size == size - 1) {
        // throw in a custom exception
        return;
    }

    actual_size++;
    container[actual_size] = new_value;

    int current_index = actual_size;
    int parent_index = (current_index - 1) / 2;

    while (current_index > 0 && container[current_index] < container[parent_index]) {
        swap_int_array_element(container, parent_index, current_index);

        current_index = parent_index;
        parent_index = (current_index - 1) / 2;
    }

}


ostream &operator<<(ostream &out, IntegerMinHeap integerMinHeap) {
    for (int i = 0; i < integerMinHeap.actual_size; i++) {
        out << integerMinHeap.container[i] << endl;
    }
    return out;
}

