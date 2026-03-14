#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int *normal_stack_array_ptr;
    int *min_stack_array_ptr;
    int stack_size;
    int next_available_index;
} MinStack;

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

MinStack* minStackCreate() {
    MinStack *min_stack_object_ptr = (
        (MinStack*)malloc(sizeof(*min_stack_object_ptr))
    );

    (min_stack_object_ptr->normal_stack_array_ptr) = NULL;
    (min_stack_object_ptr->min_stack_array_ptr) = NULL;
    (min_stack_object_ptr->stack_size) = 0;
    (min_stack_object_ptr->next_available_index) = 0;

    return min_stack_object_ptr;
}

int minStackGetMin(MinStack* min_stack_object_ptr) {
    return (
        (min_stack_object_ptr->min_stack_array_ptr)[
            (min_stack_object_ptr->next_available_index) - 1
        ]
    );
}

void minStackPush(MinStack* min_stack_object_ptr, int val) {
    int new_minimum_value = 0;
    int new_stack_size = 0;
    int *tmp_ptr_1 = NULL, *tmp_ptr_2 = NULL;

    /* Compute new minimum value. */
    if (0 == (min_stack_object_ptr->next_available_index)) {
        new_minimum_value = val;
    }
    else {
        new_minimum_value = min(val, minStackGetMin(min_stack_object_ptr));
    }

    /*
     * Push new value and new minimum value to normal stack and min stack
     * respectively.
     */
    if (
        (min_stack_object_ptr->next_available_index)
        >=
        (min_stack_object_ptr->stack_size)
    ) {
        if (0 == (min_stack_object_ptr->stack_size)) {
            new_stack_size = 4;
        }
        else {
            new_stack_size = ((min_stack_object_ptr->stack_size) << 1);
        }

        tmp_ptr_1 = (
            (int*)realloc(
                min_stack_object_ptr->normal_stack_array_ptr,
                sizeof(*(min_stack_object_ptr->normal_stack_array_ptr))
                *
                new_stack_size
            )
        );

        tmp_ptr_2 = (
            (int*)realloc(
                min_stack_object_ptr->min_stack_array_ptr,
                sizeof(*(min_stack_object_ptr->min_stack_array_ptr))
                *
                new_stack_size
            )
        );

        (min_stack_object_ptr->stack_size) = new_stack_size;
        (min_stack_object_ptr->normal_stack_array_ptr) = tmp_ptr_1;
        (min_stack_object_ptr->min_stack_array_ptr) = tmp_ptr_2;
    }

    (min_stack_object_ptr->normal_stack_array_ptr)[
        min_stack_object_ptr->next_available_index
    ] = val;
    (min_stack_object_ptr->min_stack_array_ptr)[
        min_stack_object_ptr->next_available_index
    ] = new_minimum_value;
    ++(min_stack_object_ptr->next_available_index);
}

void minStackPop(MinStack* min_stack_object_ptr) {
    --(min_stack_object_ptr->next_available_index);
}

int minStackTop(MinStack* min_stack_object_ptr) {
    return (
        (min_stack_object_ptr->normal_stack_array_ptr)[
            (min_stack_object_ptr->next_available_index) - 1
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
