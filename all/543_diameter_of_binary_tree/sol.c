#include <stddef.h>

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
int findMaximumDiameterViaPostOrderTraversal(
    int * const global_maximum_diameter_ptr,
    const struct TreeNode * const root
) {
    if (NULL == root) {
        return -1;
    }

    int left_subtree_height = 0;
    int right_subtree_height = 0;

    /* Get the height of left subtree. */
    left_subtree_height = findMaximumDiameterViaPostOrderTraversal(
        global_maximum_diameter_ptr,
        root->left
    );

    /* Get the height of right subtree. */
    right_subtree_height = findMaximumDiameterViaPostOrderTraversal(
        global_maximum_diameter_ptr,
        root->right
    );

    /*
     * Check if the diameter that pass through current root as a turning point
     * is greater than the global maximum one. If yes, update global maximum
     * value.
     */
    (*global_maximum_diameter_ptr) = max(
        *global_maximum_diameter_ptr,
        (left_subtree_height + 1) + (right_subtree_height + 1)
    );

    /* Return height of current binary tree. */
    return max(left_subtree_height, right_subtree_height) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    /*
     * Although the path of the diameter of the given binary tree may not pass
     * through the root node, but the path must pass throught a node in the
     * given binary tree as a turning point (after passing through the turning
     * point, the direction of the path of the diameter changes to the other
     * way).
     *
     * We can consider each node in the given binary tree as a turning point,
     * and compute those diameters. Among these diameters, the longest one
     * is the diameter of the given binary tree.
     *
     * To find diameter of a binary tree and it must pass-through a pre-defined
     * turning point, the length of such diameter must be the sum of the height
     * of left subtree plus 1 and the height of right subtree plus 1.
     *
     * As we need the heights of left subtree and right subtree of a root,
     * we need to use post-order traversal to do that.
     *
     * The recursive traversal function does the followin things:
     * 1. If current node is NULL, return -1.
     * 2. Call recursive traversal function on the left subtree to get the
     *    height of left subtree.
     * 3. Call recursive traversal function on the right subtree to get the
     *    height of right subtree.
     * 4. Check if the diameter that pass through the current root as a turning
     *    point is greater than the global maximum one. If yes, update
     *    the global maximum diameter value.
     * 5. Return the height of current binary tree to the caller.
     */
    int global_maximum_diameter = 0;

    findMaximumDiameterViaPostOrderTraversal(&global_maximum_diameter, root);

    return global_maximum_diameter;
}
