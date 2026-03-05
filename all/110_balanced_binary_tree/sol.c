#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool is_balanced;
    int height;
} BalancedInfoAndHeightPairST;

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
BalancedInfoAndHeightPairST computeBalancedInfoAndHeight(
    const struct TreeNode * const root
) {
    BalancedInfoAndHeightPairST balanced_info_and_height_pair_st;

    if (NULL == root) {
        balanced_info_and_height_pair_st.is_balanced = true;

        /* Empty binary tree has height -1. */
        balanced_info_and_height_pair_st.height = -1;

        return balanced_info_and_height_pair_st;
    }

    BalancedInfoAndHeightPairST left_subtree_balanced_info_and_height_pair_st;
    BalancedInfoAndHeightPairST right_subtree_balanced_info_and_height_pair_st;

    left_subtree_balanced_info_and_height_pair_st = (
        computeBalancedInfoAndHeight(root->left)
    );

    if (!(left_subtree_balanced_info_and_height_pair_st.is_balanced)) {
        balanced_info_and_height_pair_st.is_balanced = false;

        return balanced_info_and_height_pair_st;
    }

    right_subtree_balanced_info_and_height_pair_st = (
        computeBalancedInfoAndHeight(root->right)
    );

    if (!(right_subtree_balanced_info_and_height_pair_st.is_balanced)) {
        balanced_info_and_height_pair_st.is_balanced = false;

        return balanced_info_and_height_pair_st;
    }

    balanced_info_and_height_pair_st.is_balanced = (
        abs(
            left_subtree_balanced_info_and_height_pair_st.height
            -
            right_subtree_balanced_info_and_height_pair_st.height
        )
        <=
        1
    );
    balanced_info_and_height_pair_st.height = (
        max(
            left_subtree_balanced_info_and_height_pair_st.height,
            right_subtree_balanced_info_and_height_pair_st.height
        )
        +
        1
    );

    return balanced_info_and_height_pair_st;
}

bool isBalanced(struct TreeNode* root) {
    BalancedInfoAndHeightPairST balanced_info_and_height_pair_st = (
        computeBalancedInfoAndHeight(root)
    );

    return balanced_info_and_height_pair_st.is_balanced;
}
