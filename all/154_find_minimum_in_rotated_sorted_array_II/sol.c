int findMin(int* nums, int numsSize) {
    int left_index = 0, right_index = (numsSize - 1);
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = (left_index + ((right_index - left_index) >> 1));

        if ((nums[middle_index]) > (nums[right_index])) {
            /*
             * The right part is not monotonically increasing, the minimum
             * element is in the right part (middle is excluded).
             */
            left_index = (middle_index + 1);
        }
        else if ((nums[middle_index]) < (nums[right_index])) {
            /*
             * Right part is strictly increasing, the minimum element is in the
             * left part (middle is included).
             */
            right_index = middle_index;
        }
        else {
            /*
             * Right part seems has all equal values, but it might be a
             * illusion, so we just decrease right index by 1.
             *
             * For example, if nums array is [3, 3, 1, 3], the values at the
             * middle index and the right index are the same, we are not sure
             * if there exists turning point in the right part, so decrease
             * right index by 1 shrink search range. As the values at the
             * middle index and the right index are the same, this search
             * range shrinkage can still preserve the minimum value if the value
             * at the right index is the minimum value.
             */
            --right_index;
        }
    }

    return (nums[left_index]);
}
