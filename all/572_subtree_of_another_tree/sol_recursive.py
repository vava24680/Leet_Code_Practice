from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _areTwoBinaryTreesIdentical(
        self,
        tree_1_node: Optional[TreeNode],
        tree_2_node: Optional[TreeNode]
    ):
        # Use pre-order traversal to check if two given binary trees are
        # identical.
        if (not tree_1_node) and (not tree_2_node):
            return True
        elif (
            (not tree_1_node)
            or
            (not tree_2_node)
            or
            ((tree_1_node.val) != (tree_2_node.val))
        ):
            return False

        return (
            self._areTwoBinaryTreesIdentical(
                tree_1_node.left,
                tree_2_node.left
            )
            and
            self._areTwoBinaryTreesIdentical(
                tree_1_node.right,
                tree_2_node.right
            )
        )

    def isSubtree(
        self,
        root: Optional[TreeNode],
        subRoot: Optional[TreeNode]
    ) -> bool:
        # Use pre-order traversal to traverse each node in the `root` binary
        # tree, and use the current traversed node as root of a subtree to be
        # checked with the given `subRoot` binary tree to determinte
        # if they are two identical binary trees.
        #
        # Use pre-order traversal to check if two binary trees are identical.
        if not root:
            # As stated in problem's constraint, there is at least one node in
            # the `subRoot` binary tree, so a empty binary tree must be
            # different from the `subRoot` binary tree.

            return False

        return (
            self._areTwoBinaryTreesIdentical(root, subRoot)
            or
            self.isSubtree(root.left, subRoot)
            or
            self.isSubtree(root.right, subRoot)
        )
