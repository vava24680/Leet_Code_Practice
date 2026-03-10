#include <stdbool.h>
#include <stdlib.h>

int compareFunction(const void *p1, const void *p2) {
    const int i1 = (*((const int*)p1));
    const int i2 = (*((const int*)p2));

    return (i1 > i2) - (i1 < i2);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(
    int* aliceSizes,
    int aliceSizesSize,
    int* bobSizes,
    int bobSizesSize,
    int* returnSize
) {
    int *result_array_ptr = (int*)malloc(sizeof(int) * 2);
    int delta = 0;
    bool answer_found = false;

    /* Sort the given two arrays in ascending order. */
    qsort(
        (void*)aliceSizes,
        aliceSizesSize,
        sizeof(*aliceSizes),
        &compareFunction
    );
    qsort((void*)bobSizes, bobSizesSize, sizeof(*bobSizes), &compareFunction);

    for (int i = 0; i < aliceSizesSize; ++i) {
        delta += aliceSizes[i];
    }

    for (int i = 0; i < bobSizesSize; ++i) {
        delta -= bobSizes[i];
    }

    delta >>= 1;

    for (
        int i = 0, j = 0, current_candy_count_difference = 0;
        (i < aliceSizes) && (j < bobSizes);
    ) {
        current_candy_count_difference = aliceSizes[i] - bobSizes[j];

        if (delta == current_candy_count_difference) {
            result_array_ptr[0] = aliceSizes[i];
            result_array_ptr[1] = bobSizes[j];

            break;
        }
        else if (current_candy_count_difference < delta) {
            /* Increase i to increase the candy count difference. */
            ++i;
        }
        else {
            /* Increase j to decrease the candy count difference. */
            ++j;
        }
    }

    (*returnSize) = 2;

    return result_array_ptr;
}
