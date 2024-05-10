//
// Created by oussama_ib0 on 5/5/24.
//

#include "utils.h"

void swap_int_array_element(int* array, int index_one, int index_two) {
    int tmp = array[index_one];
    array[index_one] = array[index_two];
    array[index_two] = tmp;
}


void swap_node_array_element(CustomNode* array, int index_one, int index_two) {
    CustomNode tmp = array[index_one];
    array[index_one] = array[index_two];
    array[index_two] = tmp;
}