#include <stdlib.h>
#include <string.h>

static int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return (i1 > i2) - (i1 < i2);
}

int heightChecker(int* heights, int heightsSize) {
    int different_indexes_count = 0;

    int *sorted_heights_array_ptr = (
        (int*)malloc(sizeof(*sorted_heights_array_ptr) * heightsSize)
    );

    if (NULL == sorted_heights_array_ptr) {
        return 0;
    }

    memcpy(sorted_heights_array_ptr, heights, sizeof(*heights) * heightsSize);

    qsort(
        sorted_heights_array_ptr,
        heightsSize,
        sizeof(*sorted_heights_array_ptr),
        &compareFunction
    );

    for (int i = 0; i < heightsSize; ++i) {
        if (heights[i] == sorted_heights_array_ptr[i]) {
            continue;
        }

        ++different_indexes_count;
    }

    free(sorted_heights_array_ptr);
    sorted_heights_array_ptr = NULL;

    return different_indexes_count;
}
