#include <stdio.h>
#include <string.h>
#include "decode.h"

void decode_morse(TreeNode* root, const char* morse_line) {
    TreeNode* current;
    char buffer[10];
    int idx = 0;

    for (int i = 0; ; i++) {
        if (morse_line[i] == ' ' || morse_line[i] == '\0') {
            buffer[idx] = '\0';
            idx = 0;

            if (strcmp(buffer, "|") == 0) {
                printf(" ");
            } else if (strlen(buffer) > 0) {
                current = root;
                for (int j = 0; buffer[j]; j++) {
                    if (buffer[j] == '.') current = current->left;
                    else if (buffer[j] == '-') current = current->right;
                    if (!current) break;
                }
                if (current && current->letter != '\0') {
                    printf("%c", current->letter);
                }
            }

            if (morse_line[i] == '\0') break;
        } else {
            buffer[idx++] = morse_line[i];
        }
    }

    printf("\n");
}
