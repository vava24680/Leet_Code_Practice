#include <limits.h>
#include <stddef.h>

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getMinimumDifferenceViaInorderTraversal(
    int * current_minimum_two_node_values_absolute_difference_ptr,
    const struct TreeNode **previous_traversed_node_ptr_ptr,
    const struct TreeNode * const root
) {
    if (NULL == root) {
        return;
    }

    /* Traverse left subtree. */
    getMinimumDifferenceViaInorderTraversal(
        current_minimum_two_node_values_absolute_difference_ptr,
        previous_traversed_node_ptr_ptr,
        root->left
    );

    /* Traverse current root node. */
    if (NULL != (*previous_traversed_node_ptr_ptr)) {
        /*
         * If previous traversed node is not NULL, compute the absolute
         * difference between the current traversed node and the previous
         * traversed node and update the global recorded one if needed.
         */
        (*current_minimum_two_node_values_absolute_difference_ptr) = min(
            (*current_minimum_two_node_values_absolute_difference_ptr),
            (root->val) - ((*previous_traversed_node_ptr_ptr)->val)
        );
    }

    (*previous_traversed_node_ptr_ptr) = root;

    /* Traverse right subtree. */
    getMinimumDifferenceViaInorderTraversal(
        current_minimum_two_node_values_absolute_difference_ptr,
        previous_traversed_node_ptr_ptr,
        root->right
    );
}

int getMinimumDifference(struct TreeNode* root) {
    /*
     * To find the minimum absolute difference of any two values among a list,
     * the best way is sort the list first and find the minimum absolute
     * difference between any two consecutive values.
     *
     * As we are given binary search tree, we can use in-order traversal to
     * generate the sorted node values list, and we can find the minimum
     * two node values absolute different during the in-order traversal
     * without acutally generating the node values list.
     */

    /*
     * As node value is non-negative, use -1 to denote the node value
     * is not ready yet.
     */
    const struct TreeNode *previous_traversed_node_ptr = NULL;
    int current_minimum_two_node_values_absolute_difference = INT_MAX;

    getMinimumDifferenceViaInorderTraversal(
        &current_minimum_two_node_values_absolute_difference,
        &previous_traversed_node_ptr,
        root
    );

    return current_minimum_two_node_values_absolute_difference;
}
