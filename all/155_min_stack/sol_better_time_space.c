#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int *normal_stack_array_ptr;
    int *min_stack_array_ptr;
    int normal_stack_size;
    int min_stack_size;
    int normal_stack_next_available_index;
    int min_stack_next_available_index;
} MinStack;

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int* expandStackTwoTimesLarge(
    int *old_stack_array_ptr,
    int * const stack_size_ptr
) {
    int new_stack_size = 0;
    int *new_stack_array_ptr = NULL;

    if (0 == (*stack_size_ptr)) {
        new_stack_size = 4;
    }
    else {
        new_stack_size = ((*stack_size_ptr) << 1);
    }

    new_stack_array_ptr = (
        (int*)realloc(
            old_stack_array_ptr,
            sizeof(*old_stack_array_ptr) * new_stack_size
        )
    );

    (*stack_size_ptr) = new_stack_size;

    return new_stack_array_ptr;
}

MinStack* minStackCreate() {
    MinStack *min_stack_object_ptr = (
        (MinStack*)malloc(sizeof(*min_stack_object_ptr))
    );

    (min_stack_object_ptr->normal_stack_array_ptr) = NULL;
    (min_stack_object_ptr->min_stack_array_ptr) = NULL;
    (min_stack_object_ptr->normal_stack_size) = 0;
    (min_stack_object_ptr->min_stack_size) = 0;
    (min_stack_object_ptr->normal_stack_next_available_index) = 0;
    (min_stack_object_ptr->min_stack_next_available_index) = 0;

    return min_stack_object_ptr;
}

int minStackGetMin(MinStack* min_stack_object_ptr) {
    return (
        (min_stack_object_ptr->min_stack_array_ptr)[
            (min_stack_object_ptr->min_stack_next_available_index) - 1
        ]
    );
}

void minStackPush(MinStack* min_stack_object_ptr, int val) {
    if (
        (0 == (min_stack_object_ptr->normal_stack_next_available_index))
        ||
        (val <= minStackGetMin(min_stack_object_ptr))
    ) {
        /*
         * Push new minimum value to min stack if current stack is empty
         * or new value is equal or smaller than the top value in the min stack.
         */
        if (
            (min_stack_object_ptr->min_stack_next_available_index)
            >=
            (min_stack_object_ptr->min_stack_size)
        ) {
            (min_stack_object_ptr->min_stack_array_ptr) = expandStackTwoTimesLarge(
                min_stack_object_ptr->min_stack_array_ptr,
                &(min_stack_object_ptr->min_stack_size)
            );
        }

        (min_stack_object_ptr->min_stack_array_ptr)[
            min_stack_object_ptr->min_stack_next_available_index
        ] = val;

        ++(min_stack_object_ptr->min_stack_next_available_index);
    }

    /* Push new value to normal stack. */
    if (
        (min_stack_object_ptr->normal_stack_next_available_index)
        >=
        (min_stack_object_ptr->normal_stack_size)
    ) {
        (min_stack_object_ptr->normal_stack_array_ptr) = expandStackTwoTimesLarge(
            min_stack_object_ptr->normal_stack_array_ptr,
            &(min_stack_object_ptr->normal_stack_size)
        );
    }

    (min_stack_object_ptr->normal_stack_array_ptr)[
        min_stack_object_ptr->normal_stack_next_available_index
    ] = val;

    ++(min_stack_object_ptr->normal_stack_next_available_index);
}

void minStackPop(MinStack* min_stack_object_ptr) {
    int poped_value = (
        (min_stack_object_ptr->normal_stack_array_ptr)[
            (min_stack_object_ptr->normal_stack_next_available_index) - 1
        ]
    );

    --(min_stack_object_ptr->normal_stack_next_available_index);

    if (
        poped_value
        ==
        (
            (min_stack_object_ptr->min_stack_array_ptr)[
                min_stack_object_ptr->min_stack_next_available_index - 1
            ]
        )
    ) {
        --(min_stack_object_ptr->min_stack_next_available_index);
    }
}

int minStackTop(MinStack* min_stack_object_ptr) {
    return (
        (min_stack_object_ptr->normal_stack_array_ptr)[
            (min_stack_object_ptr->normal_stack_next_available_index) - 1
        ]
    );
}

void minStackFree(MinStack* min_stack_object_ptr) {
    free(min_stack_object_ptr->normal_stack_array_ptr);
    (min_stack_object_ptr->normal_stack_array_ptr) = NULL;

    free(min_stack_object_ptr->min_stack_array_ptr);
    (min_stack_object_ptr->min_stack_array_ptr) = NULL;

    free(min_stack_object_ptr);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
