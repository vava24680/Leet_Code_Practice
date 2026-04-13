from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invertTreeByPreorderTraversal(root: Optional[TreeNode]) -> None:
            if not root:
                return

            # Swap the left subtree and the right subtree.
            (root.left), (root.right) = (root.right), (root.left)

            # Continue the same procedures on the left subtree and the right
            # subtree.
            invertTreeByPreorderTraversal(root.left)
            invertTreeByPreorderTraversal(root.right)

        invertTreeByPreorderTraversal(root)

        return root
