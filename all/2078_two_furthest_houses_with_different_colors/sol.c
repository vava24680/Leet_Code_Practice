static inline int max(const int i1, const int i2) {
    return ((i1 > i2) ? i1 : i2);
}

int maxDistance(int* colors, int colorsSize) {
    int maximum_distance = 0;

    for (int left_index = 0; left_index < (colorsSize - 1); ++left_index) {
        for (
            int right_index = (colorsSize - 1);
            right_index > left_index;
            --right_index
        ) {
            /*
             * Try every house pair whose colors are different and find the
             * maximum distance among them.
             */
            if ((colors[left_index]) != (colors[right_index])) {
                maximum_distance = max(
                    maximum_distance,
                    right_index - left_index
                );

                break;
            }
        }
    }

    return maximum_distance;
}
