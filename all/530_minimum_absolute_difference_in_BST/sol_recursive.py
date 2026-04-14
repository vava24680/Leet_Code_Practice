from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        # To find the minimum absolute difference of any two values among
        # a list, the best way is sort the list first and find the minimum
        # absolute difference between any two consecutive values.
        #
        # As we are given binary search tree, we can use in-order traversal to
        # generate the sorted node values list, and we can find the minimum
        # two node values absolute different during the in-order traversal
        # without acutally generating the node values list.
        previous_traversed_node = None
        minimum_two_node_values_absolute_difference = float('inf')

        def getMinimumDifferenceViaInorderTraversal(
            root: Optional[TreeNode]
        ) -> None:
            if not root:
                return

            nonlocal previous_traversed_node

            # Traverse left subtree first.
            getMinimumDifferenceViaInorderTraversal(root.left)

            # Traverse current node, and if previous traversed node is not None,
            # compute the absolute difference between the current traversed node
            # and the previous traversed node and update the global recorded one
            # if needed.
            if previous_traversed_node is not None:
                nonlocal minimum_two_node_values_absolute_difference

                minimum_two_node_values_absolute_difference = min(
                    minimum_two_node_values_absolute_difference,
                    (root.val) - (previous_traversed_node.val)
                )

            # Update previous traversed node as current node.
            previous_traversed_node = root

            # Traverse right subtree.
            getMinimumDifferenceViaInorderTraversal(root.right)

        getMinimumDifferenceViaInorderTraversal(root)

        return minimum_two_node_values_absolute_difference
