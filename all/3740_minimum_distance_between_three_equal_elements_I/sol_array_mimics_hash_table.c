#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_ROWS_NUMBER (101)
#define MAX_COLUMNS_NUMBER (101)

static int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int minimumDistance(int* nums, int numsSize) {
    int **value_and_indices_mapping_matrix_ptr = (
        (int**)malloc(
            sizeof(*value_and_indices_mapping_matrix_ptr) * (MAX_ROWS_NUMBER)
        )
    );
    int *data_blocks_array_ptr = (
        (int*)malloc(
            sizeof(*data_blocks_array_ptr)
            *
            (MAX_ROWS_NUMBER)
            *
            (MAX_COLUMNS_NUMBER)
        )
    );
    int minimum_distance = INT_MAX;

    for (int row_index = 0; row_index < (MAX_ROWS_NUMBER); ++row_index) {
        value_and_indices_mapping_matrix_ptr[row_index] = (
            data_blocks_array_ptr + (row_index * (MAX_COLUMNS_NUMBER))
        );

        /* Reset the entry for counter. */
        value_and_indices_mapping_matrix_ptr[
            row_index
        ][
            (MAX_COLUMNS_NUMBER) - 1
        ] = 0;
    }

    {
        /*
         * Categorize all indices based on their corresponding elements' values.
         * All the indices with same element value will be categorized in the
         * same group.
         */
        int *counter_ptr = NULL;

        for (int i = 0; i < numsSize; ++i) {
            counter_ptr = &(
                value_and_indices_mapping_matrix_ptr[
                    nums[i]
                ][
                    (MAX_COLUMNS_NUMBER) - 1
                ]
            );
            value_and_indices_mapping_matrix_ptr[nums[i]][*counter_ptr] = i;

            ++(*counter_ptr);
        }
    }

    for (
        int row_index = 1, indices_count = 0;
        row_index < (MAX_ROWS_NUMBER);
        ++row_index
    ) {
        indices_count = (
            value_and_indices_mapping_matrix_ptr[
                row_index
            ][
                MAX_COLUMNS_NUMBER - 1
            ]
        );

        if (indices_count < 3) {
            /* Skip the group if there are less than 3 indices in it. */
            continue;
        }

        for (int i = 0; i < (indices_count - 3 + 1); ++i) {
            /*
             * Compute current good tuple distance and update global minimum
             * distance if needed.
             */
            minimum_distance = min(
                minimum_distance,
                (
                    value_and_indices_mapping_matrix_ptr[row_index][i + 2]
                    -
                    value_and_indices_mapping_matrix_ptr[row_index][i + 1]
                )
                +
                (
                    value_and_indices_mapping_matrix_ptr[row_index][i + 1]
                    -
                    value_and_indices_mapping_matrix_ptr[row_index][i]
                )
                +
                (
                    value_and_indices_mapping_matrix_ptr[row_index][i + 2]
                    -
                    value_and_indices_mapping_matrix_ptr[row_index][i]
                )
            );
        }
    }

    free(value_and_indices_mapping_matrix_ptr);
    value_and_indices_mapping_matrix_ptr = NULL;

    free(data_blocks_array_ptr);
    data_blocks_array_ptr = NULL;

    if (INT_MAX == minimum_distance) {
        return -1;
    }

    return minimum_distance;
}
