static inline int max(const int e1, const int e2) {
    return (e1 > e2) ? e1 : e2;
}

static inline int min(const int e1, const int e2) {
    return (e1 < e2) ? e1 : e2;
}

int maxArea(int* height, int heightSize) {
    int maximum_area = 0;
    int left_index = 0, right_index = heightSize - 1;
    int left_height = 0, right_height = 0;

    while (left_index < right_index) {
        left_height = height[left_index];
        right_height = height[right_index];

        maximum_area = max(
            maximum_area,
            min(left_height, right_height) * (right_index - left_index)
        );

        if (left_height < right_height) {
            /*
             * If left height is smaller than right height, increase the left
             * index by 1 to try if there are larger left height to form larger
             * container.
             */
            ++left_index;
        }
        else {
            /*
             * If right height is smaller than or equal to left height,
             * decrease the right index by 1 to try if there are larger right
             * height to form larger container.
             */
            --right_index;
        }
    }

    return maximum_area;
}
