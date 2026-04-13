from collections import deque
from typing import Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root

        nodes_queue = deque([root])

        while nodes_queue:
            nodes_queue_length = len(nodes_queue)

            for _ in range(nodes_queue_length):
                current_node = nodes_queue.popleft()

                # Swap the left subtree and the right subtree.
                (current_node.left, current_node.right) = (
                    current_node.right, current_node.left
                )

                if (current_node.left):
                    nodes_queue.append(current_node.left)

                if (current_node.right):
                    nodes_queue.append(current_node.right)

        return root
