from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        tree_height = 0
        current_node = root

        # Get tree height.
        while (current_node.left):
            tree_height += 1

            current_node = (current_node.left)

        left_index = 0
        right_index = (1 << tree_height)

        # Use binary search to find the first position that does not have node
        # in the last layer of the current complete binary tree.
        #
        # After the binary search, the left_index value is the number of nodes
        # in the last layer of the current complete binary tree.
        while left_index < right_index:
            middle_index = (left_index + ((right_index - left_index) >> 1))
            current_node = root

            for i in reversed(range(tree_height)):
                if 0 == ((middle_index >> i) & 0x1):
                    current_node = (current_node.left)
                else:
                    current_node = (current_node.right)

            if current_node:
                left_index = (middle_index + 1)
            else:
                right_index = middle_index

        return (((1 << tree_height) - 1) + left_index)
