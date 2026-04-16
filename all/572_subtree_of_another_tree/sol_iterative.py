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
    ) -> bool:
        current_tree_1_node = tree_1_node
        current_tree_2_node = tree_2_node
        tree_1_nodes_stack = list()
        tree_2_nodes_stack = list()

        while (
            (current_tree_1_node or tree_1_nodes_stack)
            and
            (current_tree_2_node or tree_2_nodes_stack)
        ):
            # Traverse current node
            if (
                (current_tree_1_node and (not current_tree_2_node))
                or
                ((not current_tree_1_node) and current_tree_2_node)
                or
                (
                    (current_tree_1_node and current_tree_2_node)
                    and
                    ((current_tree_1_node.val) != (current_tree_2_node.val))
                )
            ):
                # Return false if one of the following cases hold:
                # 1. Current traversed node is None but the other one is not.
                # 2. The values of currently traversed two nodes are not the
                #    same.

                return False

            if not current_tree_1_node:
                # Current traversed node is None, the next node to be traversed
                # is the right child node of the parent node.
                current_tree_1_node = (tree_1_nodes_stack.pop())
                current_tree_1_node = (current_tree_1_node.right)
            else:
                # Current node is not None, add current node to stack and the
                # next node to be traversed is the left child node.
                tree_1_nodes_stack.append(current_tree_1_node)
                current_tree_1_node = (current_tree_1_node.left)

            if not current_tree_2_node:
                # Current traversed node is None, the next node to be traversed
                # is the right child node of the parent node.
                current_tree_2_node = (tree_2_nodes_stack.pop())
                current_tree_2_node = (current_tree_2_node.right)
            else:
                # Current node is not None, add current node to stack and the
                # next node to be traversed is the left child node.
                tree_2_nodes_stack.append(current_tree_2_node)
                current_tree_2_node = (current_tree_2_node.left)

        # The two binary trees are considered identical only if the previous
        # traversal has traversed all the nodes in both binary trees.
        return all([
            not current_tree_1_node,
            not current_tree_2_node,
            not tree_1_nodes_stack,
            not tree_2_nodes_stack
        ])

    def isSubtree(
        self,
        root: Optional[TreeNode],
        subRoot: Optional[TreeNode]
    ) -> bool:
        # Use pre-order traversal to traverse each node in the `root` binary tree,
        # and use the current traversed node as root of a subtree to be checked
        # with the given `subRoot` binary tree to determinte if they are two
        # identical binary trees.
        # Use pre-order traversal to check if two binary trees are identical.
        current_traversed_node = root
        nodes_stack = list()

        while current_traversed_node or nodes_stack:
            if not current_traversed_node:
                # Current traversed node is None, the next node to be traversed
                # is the right child node of the parent node.
                current_traversed_node = nodes_stack.pop().right
            elif self._areTwoBinaryTreesIdentical(
                current_traversed_node,
                subRoot
            ):
                return True
            else:
                # Current node is not None, add current node to stack and the
                # next node to be traversed is the left child node.
                nodes_stack.append(current_traversed_node)
                current_traversed_node = (current_traversed_node.left)

        return False
