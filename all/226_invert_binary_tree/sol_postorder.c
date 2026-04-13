/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void invertTreeByPostorderTraversal(struct TreeNode * const root) {
    struct TreeNode *original_left_subtree_ptr = NULL;

    if (NULL == root) {
        return;
    }

    invertTreeByPostorderTraversal(root->left);
    invertTreeByPostorderTraversal(root->right);

    /* Swap the left subtree and right subtree. */
    original_left_subtree_ptr = root->left;
    root->left = root->right;
    root->right = original_left_subtree_ptr;

    return;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    /*
     * User recursive postorder traversal to swap the left subtree and
     * right subtree of a given root node.
     */
    invertTreeByPostorderTraversal(root);

    return root;
}
