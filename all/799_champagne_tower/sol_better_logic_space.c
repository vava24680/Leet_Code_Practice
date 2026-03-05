#include <stdlib.h>

double champagneTower(int poured, int query_row, int query_glass){
    double answer = 0.0;

    double *current_row_ptr = (double*)calloc(
        query_row + 1,
        sizeof(*current_row_ptr)
    );

    current_row_ptr[0] = ((double)poured);

    for (int row_index = 0; row_index < query_row; ++row_index) {
        for (
            int column_index = row_index;
            column_index >= 0;
            --column_index
        ) {
            if ((current_row_ptr[column_index]) >= 1.0) {
                double half_overflow_quantity = (
                    (current_row_ptr[column_index] - 1.0) / 2.0
                );
                current_row_ptr[column_index + 1] += half_overflow_quantity;
                current_row_ptr[column_index] = half_overflow_quantity;
            }
            else {
                /* No overflow case. */
                current_row_ptr[column_index] = 0.0;
            }
        }
    }

    answer = (
        (current_row_ptr[query_glass] > 1.0) ? 1.0 : current_row_ptr[query_glass]
    );

    free(current_row_ptr);
    current_row_ptr = NULL;

    return answer;
}
