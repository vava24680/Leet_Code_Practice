int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int domino_values_counter_array[100] = {0};
    int domino_value = 0, rotated_domino_value = 0;
    int result_pairs_count = 0;

    /* Compute each domino value and their count. */
    for (int i = 0; i < dominoesSize; ++i) {
        domino_value = (dominoes[i][0]) * 10 + dominoes[i][1];

        ++domino_values_counter_array[domino_value];
    }

    /*
     * After computing each domino value and their counts, we can iterate each
     * domino and use that counts information to find how many domino in the
     * rest of dominoes are considered equivalent as the current iterated one.
     *
     * This can save us unnecessary loop checking.
     */
    for (int i = 0; i < dominoesSize; ++i) {
        domino_value = (dominoes[i][0] * 10) + dominoes[i][1];
        rotated_domino_value = (dominoes[i][1] * 10) + dominoes[i][0];

        /*
         * This decrease by 1 is used to skip the current iterated domino
         * itself.
         */
        --domino_values_counter_array[domino_value];

        result_pairs_count += domino_values_counter_array[domino_value];

        /*
         * If the value of a domino is as same as the value of a rotated one,
         * we must skip finding for equivalent rotated dominoes or we will
         * count repeatedly.
         */
        if (domino_value != rotated_domino_value) {
            result_pairs_count += (
                domino_values_counter_array[rotated_domino_value]
            );
        }
    }

    return result_pairs_count;
}
