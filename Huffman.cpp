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
            container_map.insert_or_assign(potential_element->first, ++potential_element->second);
        } else {
            container_map.insert_or_assign(char_array[i], init_value);
        }
    }
}

void Huffman::encoder() {
    text_analyzer();
    construct_min_heap();
    construct_huffman_tree();
    construct_codding_tree(min_heap->getRoot(),"");
}

void Huffman::construct_min_heap() {
    for (auto it = container_map.begin(); it != container_map.end(); ++it) {
        min_heap->insert(it->first, it->second);
    }
    std::cout << *min_heap;
}

void Huffman::construct_huffman_tree() {
    while (min_heap->getActualSize() > 1) {
        CustomNode *left_element = min_heap->extract();
        CustomNode *right_element = min_heap->extract();

        int combined_frequency = left_element->value + right_element->value;
        auto *parent = new CustomNode('\0', combined_frequency);
        parent->left = left_element;
        parent->right = right_element;

        min_heap->insert(parent);
    }
    std::cout << *min_heap;
}


void Huffman::construct_codding_tree(CustomNode* root, std::string code) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        // Leaf node
        coding_map[root->key] = code;
    } else {
        // Non-leaf node
        construct_codding_tree(root->left, code + "0");
        construct_codding_tree(root->right, code + "1");
    }
}
