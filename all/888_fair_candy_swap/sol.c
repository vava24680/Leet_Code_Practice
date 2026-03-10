#include <stdbool.h>
#include <stdlib.h>

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
    int *result_array = (int*)malloc(sizeof(int) * 2);
    int alice_total_candies_number = 0;
    int bob_total_candies_number = 0;
    bool answer_found = false;

    for (int i = 0; i < aliceSizesSize; ++i) {
        alice_total_candies_number += aliceSizes[i];
    }

    for (int i = 0; i < bobSizesSize; ++i) {
        bob_total_candies_number += bobSizes[i];
    }

    for (int i = 0; i < aliceSizesSize; ++i) {
        for (int j = 0; j < bobSizesSize; ++j) {
            if (
                (alice_total_candies_number - (aliceSizes[i] << 1))
                ==
                (bob_total_candies_number - (bobSizes[j] << 1))
            ) {
                result_array[0] = aliceSizes[i];
                result_array[1] = bobSizes[j];
                answer_found = true;

                break;
            }
        }

        if (true == answer_found) {
            break;
        }
    }

    (*returnSize) = 2;

    return result_array;
}
