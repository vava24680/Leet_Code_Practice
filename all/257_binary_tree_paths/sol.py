from typing import List, Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return list()

        answer_list = list()
        node_values_strings_list = list()

        def traverseViaPreorderTraversal(root: Optional[TreeNode]) -> None:
            if not root:
                return

            nonlocal node_values_strings_list

            # Add current node value to traversed nodes' values strings list.
            node_values_strings_list.append(str(root.val))

            if (root.left) or (root.right):
                # Traverse to the left subtree and the right subtree
                # if current node is not a leaf node.
                traverseViaPreorderTraversal(root.left)
                traverseViaPreorderTraversal(root.right)
            else:
                # Current node is leaf node, add current traverse path to
                # the answer list.
                nonlocal answer_list

                answer_list.append('->'.join(node_values_strings_list))

            # Before returning back to caller, pop out the current node value
            # string.
            #
            # This is backtracking.
            node_values_strings_list.pop()

        traverseViaPreorderTraversal(root)

        return answer_list
