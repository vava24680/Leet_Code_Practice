from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        global_maximum_diameter = 0

        def findMaximumDiameterViaPostOrderTraversal(
            root: Optional[TreeNode]
        ) -> int:
            if not root:
                # Empty binary tree has height of -1.
                return -1

            # Use the variable declared in outer function.
            nonlocal global_maximum_diameter

            # Get left subtree height.
            left_subtree_height = findMaximumDiameterViaPostOrderTraversal(
                root.left
            )

            # Get right subtree height.
            right_subtree_height = findMaximumDiameterViaPostOrderTraversal(
                root.right
            )

            # Compute the value of the path that passed through current root
            # as turning point.
            current_path_length = (
                (left_subtree_height + 1) + (right_subtree_height + 1)
            )

            # Update global maximum diameter value if needed.
            global_maximum_diameter = max(
                global_maximum_diameter,
                current_path_length
            )

            # Return height of current binary tree.
            return max(left_subtree_height, right_subtree_height) + 1

        # Although the path of the diameter of the given binary tree may not
        # pass through the root node, but the path must pass throught a node
        # in the given binary tree as a turning point (after passing through
        # the turning point, the direction of the path of the diameter
        # changes to the other way).
        #
        # We can consider each node in the given binary tree as a turning point,
        # and compute those paths' lengths. Among these lengths, the longest one
        # is the diameter of the given binary tree.
        #
        # To find diameter of a binary tree and it must pass through a turning
        # point, the length of such diameter must be the sum of the height of
        # left subtree plus 1 and the height of right subtree plus 1.
        #
        # As we need the heights of left subtree and right subtree of a root,
        # we need to use post-order traversal to do that.
        #
        # The recursive traversal function does the followin things:
        # 1. If current node is NULL, return -1.
        # 2. Call recursive traversal function on the left subtree to get the
        #    height of left subtree.
        # 3. Call recursive traversal function on the right subtree to get the
        #    height of right subtree.
        # 4. Check if the length of the path that passes through the current
        #    root as a turning point is greater than the global maximum diameter
        #    value.
        # 5. Return the height of current binary tree to the caller.
        findMaximumDiameterViaPostOrderTraversal(root)

        return global_maximum_diameter
