#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compareFunction(const void *e1, const void *e2) {
    return (*((int*)e1)) - (*((int*)e2));
}

int findCandyIndex(
    int *candies,
    const int candy_size,
    const int candy_number
) {
    int left_index = 0, right_index = candy_size - 1;
    int middle_index = 0;

    while (left_index <= right_index) {
        middle_index = left_index + ((right_index - left_index) >> 1);

        if (candy_number == candies[middle_index]) {
            return middle_index;
        }
        else if (candy_number < candies[middle_index]) {
            right_index = middle_index - 1;
        }
        else {
            left_index = middle_index + 1;
        }
    }

    return -1;
}

int* fairCandySwap(
    int* aliceSizes,
    int aliceSizesSize,
    int* bobSizes,
    int bobSizesSize,
    int* returnSize
) {
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
