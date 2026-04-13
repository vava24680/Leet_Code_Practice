#include <stddef.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void invertTreeByPreorderTraversal(struct TreeNode * const root) {
    struct TreeNode *original_left_subtree_ptr = NULL;

    if (NULL == root) {
        return;
    }

    /* Swap the left subtree and right subtree. */
    original_left_subtree_ptr = root->left;
    root->left = (root->right);
    root->right = original_left_subtree_ptr;

    /* Continue the same procedure on the left subtree and the right subtree. */
    invertTreeByPreorderTraversal(root->left);
    invertTreeByPreorderTraversal(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    /*
     * User recursive preorder traversal to swap the left subtree and
     * right subtree of a given root node.
     */
    invertTreeByPreorderTraversal(root);

    return root;
}
