#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DynamicIntArray {
    int *array_ptr;
    int array_length;
    int next_available_index;
} DynamicIntArrayST;

typedef struct DynamicIntPointerArray {
    int **array_ptr;
    int array_length;
    int next_available_index;
} DynamicIntPointerArrayST;

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

bool addToResultST(
    int *nodes_values_array_ptr,
    DynamicIntPointerArrayST * const result_st_ptr
) {
    int **tmp_ptr = NULL;

    if (
        (result_st_ptr->next_available_index)
        >=
        (result_st_ptr->array_length)
    ) {
        if (0 == (result_st_ptr->array_length)) {
            result_st_ptr->array_length = 4;
        }
        else {
            (result_st_ptr->array_length) <<= 1;
        }

        tmp_ptr = (int**)realloc(
            result_st_ptr->array_ptr,
            sizeof(*(result_st_ptr->array_ptr)) * (result_st_ptr->array_length)
        );

        if (NULL == tmp_ptr) {
            return false;
        }

        result_st_ptr->array_ptr = tmp_ptr;
    }

    (result_st_ptr->array_ptr)[
        result_st_ptr->next_available_index
    ] = nodes_values_array_ptr;

    ++(result_st_ptr->next_available_index);

    return true;
}

bool addToNodesCountArrayST(
    DynamicIntArrayST * const nodes_count_array_st_ptr,
    const int nodes_count
) {
    int *tmp_ptr = NULL;

    if (
        (nodes_count_array_st_ptr->next_available_index)
        >=
        (nodes_count_array_st_ptr->array_length)
    ) {
        if (0 == (nodes_count_array_st_ptr->array_length)) {
            nodes_count_array_st_ptr->array_length = 4;
        }
        else {
            (nodes_count_array_st_ptr->array_length) <<= 1;
        }

        tmp_ptr = (int*)realloc(
            nodes_count_array_st_ptr->array_ptr,
            sizeof(*(nodes_count_array_st_ptr->array_ptr))
            *
            nodes_count_array_st_ptr->array_length
        );

        if (NULL == tmp_ptr) {
            return false;
        }

        nodes_count_array_st_ptr->array_ptr = tmp_ptr;
    }

    (nodes_count_array_st_ptr->array_ptr)[
        nodes_count_array_st_ptr->next_available_index
    ] = nodes_count;

    ++(nodes_count_array_st_ptr->next_available_index);

    return true;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(
    struct TreeNode* root,
    int* returnSize,
    int** returnColumnSizes
) {
    if (NULL == root) {
        (*returnSize) = 0;

        return NULL;
    }

    DynamicIntPointerArrayST result_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    DynamicIntArrayST nodes_count_array_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    NodeQueueST nodes_queue_st = {
        .array_ptr = (struct TreeNode**)malloc(
            sizeof(*(nodes_queue_st.array_ptr)) * 4
        ),
        .array_length = 4,
        .queue_size = 0,
        .head_index = 0,
        .next_available_index = 0,
    };
    struct TreeNode *current_node_ptr = NULL;
    int *nodes_values_array_ptr = NULL;
    int nodes_count = 0;

    pushToNodeQuqueST(root, &nodes_queue_st);

    while (!isNodeQuqueSTEmpty(&nodes_queue_st)) {
        nodes_count = getNodeQueueSize(&nodes_queue_st);
        nodes_values_array_ptr = (
            (int*)malloc(
            sizeof(*nodes_values_array_ptr) * nodes_count)
        );

        for (int i = 0; i < nodes_count; ++i) {
            popFromNodeQueueST(&current_node_ptr, &nodes_queue_st);

            nodes_values_array_ptr[i] = (current_node_ptr->val);

            if (current_node_ptr->left) {
                pushToNodeQuqueST(
                    current_node_ptr->left,
                    &nodes_queue_st
                );
            }

            if (current_node_ptr->right) {
                pushToNodeQuqueST(
                    current_node_ptr->right,
                    &nodes_queue_st
                );
            }
        }

        addToNodesCountArrayST(&nodes_count_array_st, nodes_count);
        addToResultST(nodes_values_array_ptr, &result_st);
    }

    (*returnSize) = (result_st.next_available_index);
    (*returnColumnSizes) = (nodes_count_array_st.array_ptr);

    free(nodes_queue_st.array_ptr);

    return result_st.array_ptr;
}
