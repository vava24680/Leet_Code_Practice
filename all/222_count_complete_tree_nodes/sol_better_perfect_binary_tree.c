#include <stddef.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (NULL == root) {
        return 0;
    }

    const struct TreeNode* current_node_ptr = root;
    int leftmost_depth = 0;
    int rightmost_depth = 0;

    while (NULL != (current_node_ptr->left)) {
        /* Count the depth from the root to the leftmost leaf node. */
        ++leftmost_depth;

        current_node_ptr = (current_node_ptr->left);
    }

    current_node_ptr = root;

    while (NULL != (current_node_ptr->right)) {
        /* Count the depth from the root to the rightmost leaf node. */
        ++rightmost_depth;

        current_node_ptr = (current_node_ptr->right);
    }

    if (leftmost_depth != rightmost_depth) {
        return (1 + countNodes(root->left) + countNodes(root->right));
    }

    /*
     * Current binary tree is a perfect binary tree, number of nodes in the
     * current binary tree is two to the power of (tree depth plus 1) and then
     * minus - 1.
     */
    return ((1 << (leftmost_depth + 1)) - 1);
}
