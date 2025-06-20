#include <stdio.h>
#include "traversal.h"

void inorder_traversal(TreeNode* root) {
    if (!root) return;
    inorder_traversal(root->left);
    if (root->letter) printf("%c ", root->letter);
    inorder_traversal(root->right);
}
