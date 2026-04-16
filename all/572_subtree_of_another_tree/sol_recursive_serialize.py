from typing import List, Optional


NONE_NODE_TOKEN = '"?"'


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(
        self,
        root: Optional[TreeNode],
        subRoot: Optional[TreeNode]
    ) -> bool:
        # Use pre-order traversal to serialize both trees to a string that
        # contains all nodes' values. If the serialized result of binary tree
        # `subRoot` is the sub-string of binary tree `root`, then `subRoot` is
        # a subtree of `root`.

        tokens_list_1 = list()
        tokens_list_2 = list()

        def serializeBinaryTree(
            root: Optional[TreeNode],
            tokens_list: List[str]
        ) -> None:
            # Use pre-order traversal to serialize a binary tree to a string that
            # contains all nodes' values separated by a colon. Each node value will
            # be enclosed by a pair of double quote (") to prevent accidental
            # sub-string matching.
            # For example, `root` result is '12,?,?', and `subRoot` result is
            # '2,?,?', '2,?,?' is a substring of '12,?,?', but that subtree is
            # obviously not a subtree of `root`.
            # The empty child will be represented as a "?".
            if not root:
                tokens_list.append(NONE_NODE_TOKEN)

                return

            # Traverse current node and add corresponding token to tokens list.
            tokens_list.append(f'"{root.val}"')

            serializeBinaryTree(root.left, tokens_list)
            serializeBinaryTree(root.right, tokens_list)

        serializeBinaryTree(root, tokens_list_1)
        serializeBinaryTree(subRoot, tokens_list_2)

        return (
            ','.join(tokens_list_1)
            in
            ','.join(tokens_list_2)
        )
