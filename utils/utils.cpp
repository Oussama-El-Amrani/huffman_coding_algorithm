//
// Created by oussama_ib0 on 5/5/24.
//

#include "utils.h"

void swap_int_array_element(int* array, int index_one, int index_two) {
    int tmp = array[index_one];
    array[index_one] = array[index_two];
    array[index_two] = tmp;
}