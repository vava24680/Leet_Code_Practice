from collections import deque
from typing import List, Optional


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return list()

        result_list = list()
        nodes_queue = deque([root])

        while nodes_queue:
            current_layer_nodes_count = len(nodes_queue)
            current_layer_nodes_list = list()

            for i in range(current_layer_nodes_count):
                current_node = nodes_queue.popleft()

                current_layer_nodes_list.append(current_node.val)

                if current_node.left:
                    nodes_queue.append(current_node.left)

                if current_node.right:
                    nodes_queue.append(current_node.right)

            result_list.append(current_layer_nodes_list)

        return result_list
