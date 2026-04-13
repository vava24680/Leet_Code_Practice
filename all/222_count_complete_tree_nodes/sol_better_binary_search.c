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

    int tree_height = 0;
    int left_index = 0, right_index = 0, middle_index = 0;
    const struct TreeNode *current_node_ptr = root;

    /* Get tree height. */
    while (NULL != (current_node_ptr->left)) {
        ++tree_height;

        current_node_ptr = (current_node_ptr->left);
    }

    left_index = 0;
    right_index = (1 << tree_height);

    /*
     * Use binary search to find the first position that does not have node
     * in the last layer of the current complete binary tree.
     *
     * After the binary search, the left_index value is the number of nodes
     * in the last layer of the current complete binary tree.
     */
    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        current_node_ptr = root;

        for (int i = (tree_height - 1); i >= 0; --i) {
            if (0 == ((middle_index >> i) & 0x1)) {
                current_node_ptr = (current_node_ptr->left);
            }
            else {
                current_node_ptr = (current_node_ptr->right);
            }
        }

        if (NULL != current_node_ptr) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return (((1 << tree_height) - 1) + left_index);
}
