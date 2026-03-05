#include <stdlib.h>

const int UNBALANCED_SPECIAL_RETURN_VALUE = -2;

static inline int max(const int e1, const int e2) {
    return ((e1 > e2) ? e1 : e2);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int computeHeight(const struct TreeNode * const root) {
    if (NULL == root) {
        /* Empty binary tree has height -1. */
        return -1;
    }

    int left_subtree_height = 0;
    int right_subtree_height = 0;

    left_subtree_height = computeHeight(root->left);

    if (UNBALANCED_SPECIAL_RETURN_VALUE == left_subtree_height) {
        return UNBALANCED_SPECIAL_RETURN_VALUE;
    }

    right_subtree_height = computeHeight(root->right);

    if (UNBALANCED_SPECIAL_RETURN_VALUE == right_subtree_height) {
        return UNBALANCED_SPECIAL_RETURN_VALUE;
    }

    if (abs(left_subtree_height - right_subtree_height) > 1) {
        return UNBALANCED_SPECIAL_RETURN_VALUE;
    }

    return max(left_subtree_height, right_subtree_height) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return UNBALANCED_SPECIAL_RETURN_VALUE != computeHeight(root);
}
