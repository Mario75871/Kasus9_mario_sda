#ifndef NODE_H
#define NODE_H

typedef struct TreeNode {
    char letter;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(char letter);

#endif
