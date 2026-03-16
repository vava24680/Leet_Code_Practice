static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

static inline int min(const int i1, const int i2) {
    return ((i1 < i2) ? i1 : i2);
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int domino_values_counter[100] = {0};
    int domino_value = 0;
    int result_pairs_count = 0;

    /* Compute each domino's value and their count. */
    for (int i = 0; i < dominoesSize; ++i) {
        /*
         * Use normalization to make a domino like (a, b) and the rotated
         * domino like (b, a) can have the same domino value.
         */
        domino_value = (
            max(dominoes[i][0], dominoes[i][1]) * 10
            +
            min(dominoes[i][0], dominoes[i][1])
        );

        ++domino_values_counter[domino_value];
    }

    /*
     * After computing each domino value's count, we can use that information
     * to compute how many domino pairs are the same.
     */
    for (int i = 0; i < 100; ++i) {
        /*
         * If a domino value is x, there can be
         * ((1 + (x - 1)) * (x - 1)) / 2 pairs of dominoes are considered
         * equivalent.
         */
        result_pairs_count += (
            (
                (1 + (domino_values_counter[i] - 1))
                *
                (domino_values_counter[i] - 1)
            )
            >> 1
        );
    }

    return result_pairs_count;
}
