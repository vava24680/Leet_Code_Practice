#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int root_value;
    int value;
} RootValueAndValuePairST;

static int RootValueAndValuePairSTCompareFunction(
    const void *p1,
    const void *p2
) {
    const RootValueAndValuePairST *rvp_ptr1 = (
        (const RootValueAndValuePairST*)p1
    );
    const RootValueAndValuePairST *rvp_ptr2 = (
        (const RootValueAndValuePairST*)p2
    );

    if ((rvp_ptr1->root_value) == (rvp_ptr2->root_value)) {
        return (
            ((rvp_ptr1->value) > (rvp_ptr2->value))
            -
            ((rvp_ptr1->value) < (rvp_ptr2->value))
        );
    }

    return (
        ((rvp_ptr1->root_value) > (rvp_ptr2->root_value))
        -
        ((rvp_ptr1->root_value) < (rvp_ptr2->root_value))
    );
}

static int unionFindFind(
    int *parents_array_ptr,
    const int parents_array_length,
    const int i
) {
    if (i >= parents_array_length) {
        return -1;
    }

    int root = i, original_parent = 0;
    int current_i = i;

    while (root != (parents_array_ptr[root])) {
        root = (parents_array_ptr[root]);
    }

    /*
     * Do path compresion to make all the nodes that have same ancestor point to
     * the ancestor directly.
     */
    while (root != (parents_array_ptr[current_i])) {
        original_parent = (parents_array_ptr[current_i]);
        parents_array_ptr[current_i] = root;
        current_i = original_parent;
    }

    return root;
}

static void unionFindUnion(
    int * parents_array_ptr,
    const int parents_array_length,
    const int i,
    const int j
) {
    const int root_of_i = unionFindFind(
        parents_array_ptr,
        parents_array_length,
        i
    );
    const int root_of_j = unionFindFind(
        parents_array_ptr,
        parents_array_length,
        j
    );

    if (root_of_i == root_of_j) {
        return;
    }

    parents_array_ptr[root_of_j] = root_of_i;
}

int minimumHammingDistance(
    int* source,
    int sourceSize,
    int* target,
    int targetSize,
    int** allowedSwaps,
    int allowedSwapsSize,
    int* allowedSwapsColSize
) {
    int minimum_hamming_distance = sourceSize;
    int *parents_array_ptr = (
        (int*)malloc(sizeof(*parents_array_ptr) * sourceSize)
    );
    RootValueAndValuePairST *root_value_and_value_pairs_st_array_ptr = (
        (RootValueAndValuePairST*)malloc(
            sizeof(*root_value_and_value_pairs_st_array_ptr) * sourceSize * 2
        )
    );
    RootValueAndValuePairST *source_root_value_and_value_pairs_st_array_ptr = (
        root_value_and_value_pairs_st_array_ptr
    );
    RootValueAndValuePairST *target_root_value_and_value_pairs_st_array_ptr = (
        root_value_and_value_pairs_st_array_ptr + sourceSize
    );

    for (int i = 0; i < sourceSize; ++i) {
        parents_array_ptr[i] = i;
    }

    /* Set union find data structure. */
    for (int k = 0, i = 0, j = 0; k < allowedSwapsSize; ++k) {
        i = (allowedSwaps[k][0]);
        j = (allowedSwaps[k][1]);

        unionFindUnion(parents_array_ptr, sourceSize, i, j);
    }

    /*
     * Construct the root value (parent value) and value pairs array for source
     * array and target array.
     */
    for (int i = 0, root_of_i = 0; i < sourceSize; ++i) {
        root_of_i = unionFindFind(parents_array_ptr, sourceSize, i);

        (source_root_value_and_value_pairs_st_array_ptr[i]).root_value = (
            root_of_i
        );
        (source_root_value_and_value_pairs_st_array_ptr[i]).value = (source[i]);
        (target_root_value_and_value_pairs_st_array_ptr[i]).root_value = (
            root_of_i
        );
        (target_root_value_and_value_pairs_st_array_ptr[i]).value = (target[i]);
    }

    /*
     * Sort the source root value and value pairs array.
     * After sorting, the indices that are in the same group will be grouped
     * together and their values will be sorted too.
     */
    qsort(
        (void*)source_root_value_and_value_pairs_st_array_ptr,
        sourceSize,
        sizeof(*source_root_value_and_value_pairs_st_array_ptr),
        &RootValueAndValuePairSTCompareFunction
    );

    /*
     * Sort the target root value and value pairs array.
     * After sorting, the indices that are in the same group will be grouped
     * together and their values will be sorted too.
     */
    qsort(
        (void*)target_root_value_and_value_pairs_st_array_ptr,
        targetSize,
        sizeof(*target_root_value_and_value_pairs_st_array_ptr),
        &RootValueAndValuePairSTCompareFunction
    );

    /*
     * Use two pointers to iterated the source root value and value pairs
     * array and the target root value and value pairs array to find how
     * many numbers in the target array can be fulfilled by swapping some
     * numbers in the source array under the given swap pairs constraint.
     */
    for (int i = 0, j = 0; (i < sourceSize) && (j < targetSize);) {
        if (
            ((source_root_value_and_value_pairs_st_array_ptr[i]).root_value)
            ==
            ((target_root_value_and_value_pairs_st_array_ptr[j]).root_value)
        ) {
            if (
                ((source_root_value_and_value_pairs_st_array_ptr[i]).value)
                ==
                ((target_root_value_and_value_pairs_st_array_ptr[j]).value)
            ) {
                --minimum_hamming_distance;
                ++i;
                ++j;
            }
            else if (
                ((source_root_value_and_value_pairs_st_array_ptr[i]).value)
                <
                ((target_root_value_and_value_pairs_st_array_ptr[j]).value)
            ) {
                ++i;
            }
            else {
                ++j;
            }
        }
        else if (i > j) {
            j = i;
        }
        else {
            i = j;
        }
    }

    free(parents_array_ptr);
    parents_array_ptr = NULL;

    free(root_value_and_value_pairs_st_array_ptr);
    root_value_and_value_pairs_st_array_ptr = NULL;
    source_root_value_and_value_pairs_st_array_ptr = NULL;
    target_root_value_and_value_pairs_st_array_ptr = NULL;

    return minimum_hamming_distance;
}
