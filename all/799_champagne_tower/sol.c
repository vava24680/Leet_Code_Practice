#include <stdlib.h>
#include <string.h>

double champagneTower(int poured, int query_row, int query_glass){
    double answer = 0.0;

    double *current_row_ptr = (double*)calloc(
        query_row + 1 + 1,
        sizeof(*current_row_ptr)
    );
    double *next_row_ptr = (double*)calloc(
        query_row + 1 + 1,
        sizeof(*next_row_ptr)
    );
    double *tmp_ptr = NULL;

    next_row_ptr[0] = ((double)poured);

    for (int row_index = 0; row_index < (query_row + 1); ++row_index) {
        tmp_ptr = current_row_ptr;
        current_row_ptr = next_row_ptr;
        next_row_ptr = tmp_ptr;

#if 1
        memset(
            (void*)next_row_ptr,
            0,
            sizeof(*next_row_ptr) * (query_row + 1 + 1)
        );
#else
        for (int i = 0; i < (query_row + 1 + 1); ++i) {
            next_row_ptr[i] = 0.0;
        }
#endif

        for (
            int column_index = 0;
            column_index < (row_index + 1);
            ++column_index
        ) {
            if ((current_row_ptr[column_index]) >= 1.0) {
                next_row_ptr[column_index] += (
                    (current_row_ptr[column_index] - 1.0) / 2.0
                );
                next_row_ptr[column_index + 1] += (
                    (current_row_ptr[column_index] - 1.0) / 2.0
                );
                current_row_ptr[column_index] = 1.0;
            }
        }
    }

    answer = current_row_ptr[query_glass];

    free(current_row_ptr);
    current_row_ptr = NULL;

    free(next_row_ptr);
    next_row_ptr = NULL;

    return answer;
}
