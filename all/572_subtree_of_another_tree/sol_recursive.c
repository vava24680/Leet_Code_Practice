#include <stdbool.h>
#include <stddef.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isTwoBinaryTreesIdentical(
    const struct TreeNode * const tree_1_node,
    const struct TreeNode * const tree_2_node
) {
    /* Use pre-order traversal to check if two given binary trees are identical. */
    if ((NULL == tree_1_node) && (NULL == tree_2_node)) {
        return true;
    }
    else if (
        (NULL == tree_1_node)
        ||
        (NULL == tree_2_node)
        ||
        ((tree_1_node->val) != (tree_2_node->val))
    ) {
        return false;
    }

    return (
        isTwoBinaryTreesIdentical(tree_1_node->left, tree_2_node->left)
        &&
        isTwoBinaryTreesIdentical(tree_1_node->right, tree_2_node->right)
    );
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    /*
     * Use pre-order traversal to traverse each node in the `root` binary tree,
     * and use the current traversed node as root of a subtree to be checked
     * with the given `subRoot` binary tree to determinte if they are two
     * identical binary trees.
     *
     * Use pre-order traversal to check if two binary trees are identical.
     */
    if (NULL == root) {
        /*
         * As stated in problem's constraint, there is at least one node in
         * the `subRoot` binary tree, so a empty binary tree must be different
         * from the `subRoot` binary tree.
         */
        return false;
    }

    return (
        isTwoBinaryTreesIdentical(root, subRoot)
        ||
        isSubtree(root->left, subRoot)
        ||
        isSubtree(root->right, subRoot)
    );
}
