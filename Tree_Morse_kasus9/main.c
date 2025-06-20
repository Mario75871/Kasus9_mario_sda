#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "tree_builder.h"
#include "traversal.h"
#include "encode.h"
#include "decode.h"
#include "cleanup.h"

int main() {
    TreeNode* root = create_node('\0');
    build_morse_tree(root);

    int choice;
    char input[512];

    while (1) {
        printf("\nMenu:\n1. Teks ke Morse\n2. Morse ke Teks\n3. Traversal\n4. Keluar\nPilihan: ");
        scanf("%d", &choice);
        getchar(); // hapus newline

        switch (choice) {
            case 1:
                printf("Masukkan teks:\n> ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                encode_text(input);
                break;
            case 2:
                printf("Masukkan Morse (pisah huruf dengan spasi, kata dengan '|'):\n> ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                decode_morse(root, input);
                break;
            case 3:
                printf("Traversal Inorder:\n");
                inorder_traversal(root);
                printf("\n");
                break;
            case 4:
                free_tree(root);
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
}
