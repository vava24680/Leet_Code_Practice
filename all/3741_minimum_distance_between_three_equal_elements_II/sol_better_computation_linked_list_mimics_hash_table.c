#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_VALUE (100000)

typedef struct NodeStruct {
    int index;
    struct NodeStruct *next;
} NodeST;

static int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minimumDistance(int* nums, int numsSize) {
    NodeST** head_node_ptrs_array_ptr = (
        (NodeST**)calloc(MAX_VALUE + 1, sizeof(*head_node_ptrs_array_ptr))
    );
    NodeST* nodes_array_ptr = (
        (NodeST*)malloc(sizeof(*nodes_array_ptr) * numsSize)
    );
    NodeST* current_node_ptr = NULL;
    int minimum_distance = INT_MAX;

    for (int i = 0; i < numsSize; ++i) {
        /* Set the index value in the corresponding node. */
        (nodes_array_ptr[i]).index = i;

        /*
         * Insert the corresponding node to the head of the corresponding linked
         * list.
         */
        (nodes_array_ptr[i]).next = (head_node_ptrs_array_ptr[nums[i]]);
        (head_node_ptrs_array_ptr[nums[i]]) = &(nodes_array_ptr[i]);
    }

    for (int i = 1; i <= MAX_VALUE; ++i) {
        /* Get the head node ptr of a linked list. */
        current_node_ptr = (head_node_ptrs_array_ptr[i]);

        if (NULL == current_node_ptr) {
            /* Continue to next linked list if current one is empty. */
            continue;
        }

        while ((current_node_ptr->next) && (current_node_ptr->next->next)) {
            /*
             * If next node and the node after the next node both exist, there
             * is good tuple, we can compute its distance and update global
             * minimum distance if needed.
             *
             * Note: current node has larger index value compared to the index
             * values store in the next node and the node after the next node.
             */
            minimum_distance = min(
                minimum_distance,
                ((current_node_ptr->index) - (current_node_ptr->next->next->index))
                <<
                1
            );

            /* Move to next node. */
            current_node_ptr = (current_node_ptr->next);
        }
    }

    free(head_node_ptrs_array_ptr);
    head_node_ptrs_array_ptr = NULL;

    free(nodes_array_ptr);
    nodes_array_ptr = NULL;

    if (INT_MAX == minimum_distance) {
        return -1;
    }

    return minimum_distance;
}
