#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int *array_ptr;
    int array_length;
    int next_available_index;
} FixedSizeIndexStackST;

static bool isStackFull(
    const FixedSizeIndexStackST *fixed_size_index_stack_st_ptr
) {
    return (
        (fixed_size_index_stack_st_ptr->next_available_index)
        ==
        (fixed_size_index_stack_st_ptr->array_length)
    );
}

static bool isStackEmpty(
    const FixedSizeIndexStackST *fixed_size_index_stack_st_ptr
) {
    return (0 == (fixed_size_index_stack_st_ptr->next_available_index));
}

static bool pushIndexIntoStackFixedSizeIndexStackST(
    FixedSizeIndexStackST *fixed_size_index_stack_st_ptr,
    const int index_to_be_pushed
) {
    if (isStackFull(fixed_size_index_stack_st_ptr)) {
        return false;
    }

    (fixed_size_index_stack_st_ptr->array_ptr)[
        fixed_size_index_stack_st_ptr->next_available_index
    ] = index_to_be_pushed;

    ++(fixed_size_index_stack_st_ptr->next_available_index);

    return true;
}

static int popIndexFromFixedSizeIndexStackST(
    FixedSizeIndexStackST *fixed_size_index_stack_st_ptr
) {
    if (isStackEmpty(fixed_size_index_stack_st_ptr)) {
        return -1;
    }

    --(fixed_size_index_stack_st_ptr->next_available_index);

    return (
        (fixed_size_index_stack_st_ptr->array_ptr)[
            fixed_size_index_stack_st_ptr->next_available_index
        ]
    );
}

bool canReach(int* arr, int arrSize, int start) {
    bool result = false;
    int popped_index = 0;
    int destination_index_after_left_jump = 0;
    int destination_index_after_right_jump = 0;
    FixedSizeIndexStackST fixed_size_index_stack_st = {
        .array_length = arrSize,
        .next_available_index = 0,
    };

    (fixed_size_index_stack_st.array_ptr) = (
        (int*)malloc(
            sizeof(*(fixed_size_index_stack_st.array_ptr))
            *
            (fixed_size_index_stack_st.array_length)
        )
    );
    bool *indices_visited_array_ptr = (
        (bool*)calloc(arrSize, sizeof(*indices_visited_array_ptr))
    );

    /* Mark the start index as visited. */
    indices_visited_array_ptr[start] = true;

    /* Push the start index into stack. */
    pushIndexIntoStackFixedSizeIndexStackST(&fixed_size_index_stack_st, start);

    /*
     * Use iterative DFS to check if we can jump to an index whose value is 0
     * from the start index.
     */
    while (!isStackEmpty(&fixed_size_index_stack_st)) {
        popped_index = popIndexFromFixedSizeIndexStackST(
            &fixed_size_index_stack_st
        );

        if (0 == (arr[popped_index])) {
            result = true;

            break;
        }

        destination_index_after_left_jump = (
            popped_index - (arr[popped_index])
        );

        if (
            (destination_index_after_left_jump >= 0)
            &&
            (!(indices_visited_array_ptr[destination_index_after_left_jump]))
        ) {
            indices_visited_array_ptr[destination_index_after_left_jump] = true;
            pushIndexIntoStackFixedSizeIndexStackST(
                &fixed_size_index_stack_st,
                destination_index_after_left_jump
            );
        }

        destination_index_after_right_jump = (
            popped_index + (arr[popped_index])
        );

        if (
            (destination_index_after_right_jump < arrSize)
            &&
            (!(indices_visited_array_ptr[destination_index_after_right_jump]))
        ) {
            indices_visited_array_ptr[destination_index_after_right_jump] = true;
            pushIndexIntoStackFixedSizeIndexStackST(
                &fixed_size_index_stack_st,
                destination_index_after_right_jump
            );
        }
    }

    free(fixed_size_index_stack_st.array_ptr);
    (fixed_size_index_stack_st.array_ptr) = NULL;

    free(indices_visited_array_ptr);
    indices_visited_array_ptr = NULL;

    return result;
}
