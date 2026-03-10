#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compareFunction(const void *e1, const void *e2) {
    return (*((int*)e1)) - (*((int*)e2));
}

int findCandyIndex(
    int *candy_boxes_array_ptr,
    const int candy_boxes_number,
    const int candy_number
) {
    /*
     * Use binary search to find the first box whose candies number is equal to
     * or greater than the given candy number.
     */
    int left_index = 0, right_index = candy_boxes_number;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = left_index + ((right_index - left_index) >> 1);

        if (candy_number > candy_boxes_array_ptr[middle_index]) {
            left_index = middle_index + 1;
        }
        else {
            right_index = middle_index;
        }
    }

    if (
        (left_index >= candy_boxes_number)
        ||
        (candy_number != candy_boxes_array_ptr[left_index])
    ) {
        return -1;
    }

    return left_index;
}

int* fairCandySwap(
    int* aliceSizes,
    int aliceSizesSize,
    int* bobSizes,
    int bobSizesSize,
    int* returnSize
) {
    /* Check notes for detailed explanation. */
    int *result_array = (int*)malloc(sizeof(int) * 2);
    int alice_total_candies_number = 0;
    int bob_total_candies_number = 0;
    int candy_index = 0, delta = 0;

    /* Sort Alice's candies first. */
    qsort(
        (void*)aliceSizes,
        aliceSizesSize,
        sizeof(*aliceSizes),
        &compareFunction
    );

    for (int i = 0; i < aliceSizesSize; ++i) {
        delta += aliceSizes[i];
    }

    for (int i = 0; i < bobSizesSize; ++i) {
        delta -= bobSizes[i];
    }

    delta = delta / 2;

    for (int i = 0; i < bobSizesSize; ++i) {
        /* Get candy box index from Alice's candy boxes. */
        if (
            -1
            !=
            findCandyIndex(aliceSizes, aliceSizesSize, bobSizes[i] + delta)
        ) {
            result_array[0] = bobSizes[i] + delta;
            result_array[1] = bobSizes[i];

            break;
        }
    }

    (*returnSize) = 2;

    return result_array;
}
