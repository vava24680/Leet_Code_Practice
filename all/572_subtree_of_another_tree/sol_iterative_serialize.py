from typing import Optional


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

        def iterativePreOrderTraversalserializeBinaryTree(
            root: Optional[TreeNode]
        ):
            # Use pre-order traversal to serialize a binary tree to a string
            # that contains all nodes' values separated by a colon.
            # Each node value will be enclosed by a pair of double quote (")
            # to prevent accidental sub-string matching.
            # For example, `root` result is '12,?,?', and `subRoot` result is
            # '2,?,?', '2,?,?' is a substring of '12,?,?', but that subtree is
            # obviously not a subtree of `root`.
            # The empty child will be represented as a "?".
            if not root:
                return NONE_NODE_TOKEN

            current_node = root
            nodes_stack = list()
            tokens_list = list()

            while current_node or nodes_stack:
                if current_node:
                    tokens_list.append(f'"{current_node.val}"')
                    nodes_stack.append(current_node)

                    current_node = (current_node.left)
                else:
                    tokens_list.append(NONE_NODE_TOKEN)
                    current_node = (nodes_stack.pop().right)

            if not current_node:
                # Do not forget the last traversed node which is None.
                tokens_list.append(NONE_NODE_TOKEN)

            return ','.join(tokens_list)

        return (
            iterativePreOrderTraversalserializeBinaryTree(subRoot)
            in
            iterativePreOrderTraversalserializeBinaryTree(root)
        )
