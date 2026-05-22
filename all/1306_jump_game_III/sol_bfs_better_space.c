#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int *array_ptr;
    int array_length;
    int previous_read_index;
    int previous_write_index;
} FixedSizeIndexQueueST;

static bool isQueueFull(
    const FixedSizeIndexQueueST *fixed_size_index_queue_st_ptr
) {
    return (
        (
            ((fixed_size_index_queue_st_ptr->previous_write_index) + 1)
            %
            (fixed_size_index_queue_st_ptr->array_length)
        )
        ==
        (fixed_size_index_queue_st_ptr->previous_read_index)
    );
}

static bool isQueueEmpty(
    const FixedSizeIndexQueueST *fixed_size_index_queue_st_ptr
) {
    return (
        (fixed_size_index_queue_st_ptr->previous_read_index)
        ==
        (fixed_size_index_queue_st_ptr->previous_write_index)
    );
}

static bool enqueIndex(
    FixedSizeIndexQueueST *fixed_size_index_queue_st_ptr,
    const int index_to_be_enqued
) {
    if (isQueueFull(fixed_size_index_queue_st_ptr)) {
        return false;
    }

    int write_index = (
        ((fixed_size_index_queue_st_ptr->previous_write_index) + 1)
        %
        (fixed_size_index_queue_st_ptr->array_length)
    );

    (fixed_size_index_queue_st_ptr->array_ptr)[write_index] = (
        index_to_be_enqued
    );

    (fixed_size_index_queue_st_ptr->previous_write_index) = write_index;

    return true;
}

static int popIndexIndexQueueST(
    FixedSizeIndexQueueST *fixed_size_index_queue_st_ptr
) {
    if (isQueueEmpty(fixed_size_index_queue_st_ptr)) {
        return -1;
    }

    int read_index = (
        ((fixed_size_index_queue_st_ptr->previous_read_index) + 1)
        %
        (fixed_size_index_queue_st_ptr->array_length)
    );

    (fixed_size_index_queue_st_ptr->previous_read_index) = read_index;

    return ((fixed_size_index_queue_st_ptr->array_ptr)[read_index]);
}

bool canReach(int* arr, int arrSize, int start) {
    bool result = false;
    int popped_index = 0;
    int destination_index_after_left_jump = 0;
    int destination_index_after_right_jump = 0;
    FixedSizeIndexQueueST fixed_size_index_queue_st = {
        .array_length = (arrSize + 1),
        .previous_read_index = 0,
        .previous_write_index = 0,
    };

    (fixed_size_index_queue_st.array_ptr) = (
        (int*)malloc(
            sizeof(*(fixed_size_index_queue_st.array_ptr))
            *
            (fixed_size_index_queue_st.array_length)
        )
    );

    /* Mark the start index as visited by change its element value to negative. */
    arr[start] = (-(arr[start]));

    /* Enque the start index. */
    enqueIndex(&fixed_size_index_queue_st, start);

    /*
     * Use BFS to check if we can jump to an index whose value is 0 from the
     * start index.
     */
    while (!isQueueEmpty(&fixed_size_index_queue_st)) {
        popped_index = popIndexIndexQueueST(&fixed_size_index_queue_st);

        if (0 == (arr[popped_index])) {
            result = true;

            break;
        }

        destination_index_after_left_jump = (
            popped_index - (abs(arr[popped_index]))
        );

        if (
            (destination_index_after_left_jump >= 0)
            &&
            ((arr[destination_index_after_left_jump]) >= 0)
        ) {
            /*
             * Mark an index as visited by changing its element value to
             * negative value.
             */
            arr[destination_index_after_left_jump] = (
                -(arr[destination_index_after_left_jump])
            );
            enqueIndex(
                &fixed_size_index_queue_st,
                destination_index_after_left_jump
            );
        }

        destination_index_after_right_jump = (
            popped_index + (abs(arr[popped_index]))
        );

        if (
            (destination_index_after_right_jump < arrSize)
            &&
            ((arr[destination_index_after_right_jump]) >= 0)
        ) {
            /*
             * Mark an index as visited by changing its element value to
             * negative value.
             */
            arr[destination_index_after_right_jump] = (
                -(arr[destination_index_after_right_jump])
            );
            enqueIndex(
                &fixed_size_index_queue_st,
                destination_index_after_right_jump
            );
        }
    }

    free(fixed_size_index_queue_st.array_ptr);
    (fixed_size_index_queue_st.array_ptr) = NULL;

    return result;
}
