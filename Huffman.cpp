//
// Created by oussama_ib0 on 4/26/24.
//

#include <cstring>
#include "Huffman.h"

void Huffman::text_analyzer() {
    const int init_value = 1;
    const char *char_array = text.c_str();

    for (size_t i = 0; i < strlen(char_array); i++) {
        auto potential_element = container_map.find(char_array[i]);

        if (potential_element != container_map.end()) {
            container_map.insert_or_assign(potential_element->first, potential_element->second++);
        } else {
            container_map.insert_or_assign(char_array[i], init_value);
        }
    }
}

void Huffman::encoder() {
    text_analyzer();
}
