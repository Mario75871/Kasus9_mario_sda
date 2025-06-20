#include <string.h>
#include "tree_builder.h"
#include "node.h"

typedef struct {
    char letter;
    const char* code;
} MorseCode;

MorseCode morse_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}, {'0', "-----"}, {' ', "|"}
};

void insert_morse(TreeNode* root, const char* code, char letter) {
    TreeNode* current = root;
    while (*code) {
        if (*code == '.') {
            if (!current->left) current->left = create_node('\0');
            current = current->left;
        } else if (*code == '-') {
            if (!current->right) current->right = create_node('\0');
            current = current->right;
        }
        code++;
    }
    current->letter = letter;
}

void build_morse_tree(TreeNode* root) {
    int n = sizeof(morse_table) / sizeof(MorseCode);
    for (int i = 0; i < n; i++) {
        insert_morse(root, morse_table[i].code, morse_table[i].letter);
    }
}
