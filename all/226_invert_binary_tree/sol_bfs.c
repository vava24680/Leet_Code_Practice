#include <stdlib.h>
#include <stddef.h>

typedef struct NodeQueue {
    struct TreeNode **array_ptr;
    int array_length;
    int queue_size;
    int head_index;
    int next_available_index;
} NodeQueueST;

bool isNodeQuqueSTFull(const NodeQueueST * const queue_st_ptr) {
    return ((queue_st_ptr->array_length) == (queue_st_ptr->queue_size));
}

bool isNodeQuqueSTEmpty(const NodeQueueST * const queue_st_ptr) {
    return (0 == (queue_st_ptr->queue_size));
}

int getNodeQueueSize(const NodeQueueST * const queue_st_ptr) {
    return (queue_st_ptr->queue_size);
}

bool popFromNodeQueueST(
    struct TreeNode** const poped_node_ptr_ptr,
    NodeQueueST * const queue_st_ptr
) {
    if (isNodeQuqueSTEmpty(queue_st_ptr)) {
        return false;
    }

    (*poped_node_ptr_ptr) = (
        (queue_st_ptr->array_ptr)[queue_st_ptr->head_index]
    );

    --(queue_st_ptr->queue_size);

    queue_st_ptr->head_index = (
        ((queue_st_ptr->head_index) + 1) % (queue_st_ptr->array_length)
    );

    return true;
}
void pushToNodeQuqueST(
    struct TreeNode *node_ptr,
    NodeQueueST * const queue_st_ptr
) {
    if (isNodeQuqueSTFull(queue_st_ptr)) {
        int new_array_length = ((queue_st_ptr->array_length) << 1);
        struct TreeNode **new_array_ptr = (struct TreeNode**)malloc(
            sizeof(*new_array_ptr) * new_array_length
        );

        for (
            int i = 0, j = (queue_st_ptr->head_index);
            i < (queue_st_ptr->array_length);
            ++i
        ) {
            new_array_ptr[i] = queue_st_ptr->array_ptr[j];
            j = ((j + 1) % (queue_st_ptr->array_length));
        }

        /* Deallocate old queue. */
        free(queue_st_ptr->array_ptr);

        queue_st_ptr->array_ptr = new_array_ptr;
        queue_st_ptr->head_index = 0;
        queue_st_ptr->next_available_index = (queue_st_ptr->array_length);
        queue_st_ptr->array_length = new_array_length;
    }

    (queue_st_ptr->array_ptr)[queue_st_ptr->next_available_index] = (
        node_ptr
    );

    ++(queue_st_ptr->queue_size);
    queue_st_ptr->next_available_index = (
        ((queue_st_ptr->next_available_index) + 1)
        %
        (queue_st_ptr->array_length)
    );
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (NULL == root) {
        return root;
    }

    struct TreeNode *current_node_ptr = NULL;
    struct TreeNode *tmp_node_ptr = NULL;
    NodeQueueST nodes_queue_st = {
        .array_ptr = (struct TreeNode**)malloc(
            sizeof(*(nodes_queue_st.array_ptr)) * 4
        ),
        .array_length = 4,
        .queue_size = 0,
        .head_index = 0,
        .next_available_index = 0,
    };

    pushToNodeQuqueST(root, &nodes_queue_st);

    while (!isNodeQuqueSTEmpty(&nodes_queue_st)) {
        popFromNodeQueueST(&current_node_ptr, &nodes_queue_st);

        /* Swap the left subtree and the right subtree of the current node. */
        tmp_node_ptr = (current_node_ptr->left);
        (current_node_ptr->left) = (current_node_ptr->right);
        (current_node_ptr->right) = tmp_node_ptr;

        if (NULL != (current_node_ptr->left)) {
            pushToNodeQuqueST(current_node_ptr->left, &nodes_queue_st);
        }

        if (NULL != (current_node_ptr->right)) {
            pushToNodeQuqueST(current_node_ptr->right, &nodes_queue_st);
        }
    }

    free(nodes_queue_st.array_ptr);
    (nodes_queue_st.array_ptr) = NULL;

    return root;
}
