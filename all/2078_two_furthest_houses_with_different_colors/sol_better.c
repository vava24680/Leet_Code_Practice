static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

int maxDistance(int* colors, int colorsSize) {
    int furthest_different_color_house_index_against_first_house = 0;
    int furthest_different_color_house_index_against_last_house = (
        colorsSize - 1
    );

    for (int i = (colorsSize - 1); i > 0; --i) {
        /*
         * Start from the last house, find the first house whose color is
         * different from the first house and record that house's index.
         */
        if ((colors[0]) != (colors[i])) {
            furthest_different_color_house_index_against_first_house = i;

            break;
        }
    }

    for (int i = 0; i < colorsSize; ++i) {
        /*
         * Start from the first house, find the first house whose color is
         * different from the last house and record that house's index.
         */
        if ((colors[colorsSize - 1]) != (colors[i])) {
            furthest_different_color_house_index_against_last_house = i;

            break;
        }
    }

    /*
     * Check notes for why answer is the larger value among the following two
     * values:
     * 1. The distance between the first house and the first house from the right
     *    side and has different color from the first house.
     * 2. The distance between the last house and the first house from the left
     *    side and has different color from the last house.
     */
    return max(
        furthest_different_color_house_index_against_first_house - 0,
        (
            (colorsSize - 1)
            -
            furthest_different_color_house_index_against_last_house
        )
    );
}
