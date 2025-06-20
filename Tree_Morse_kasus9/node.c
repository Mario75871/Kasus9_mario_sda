#include <stdlib.h>
#include "node.h"

TreeNode* create_node(char letter) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->letter = letter;
    node->left = NULL;
    node->right = NULL;
    return node;
}
