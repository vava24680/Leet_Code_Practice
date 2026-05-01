int findFirstGreaterThanOrEqualIndex(
    const int * const array_ptr,
    const int start_index,
    const int end_index,
    const int target_value
) {
    /*
     * Use binary search to find the first index whose value is greater than
     * the target value in the given array with in the index range from start
     * index (inclusive) to end index (inclusive).
     */
    int left_index = 0, right_index = end_index;
    int middle_index = 0;

    while (left_index < right_index) {
        middle_index = left_index + ((right_index - left_index) >> 1);

        if ((array_ptr[middle_index]) < target_value) {
            left_index = (middle_index + 1);
        }
        else {
            right_index = middle_index;
        }
    }

    return left_index;
}

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    const int *shorter_array_ptr = ((nums1Size < nums2Size) ? nums1 : nums2);
    const int *longer_array_ptr = ((nums1Size >= nums2Size) ? nums1 : nums2);
    const int shorter_array_length = (
        (nums1Size < nums2Size) ? nums1Size : nums2Size
    );
    const int longer_array_length = (
        (nums1Size >= nums2Size) ? nums1Size : nums2Size
    );

    int first_greater_than_or_equal_index = 0;

    for (int i = 0; i < shorter_array_length; ++i) {
        first_greater_than_or_equal_index = findFirstGreaterThanOrEqualIndex(
            longer_array_ptr,
            0,
            longer_array_length,
            shorter_array_ptr[i]
        );

        if (first_greater_than_or_equal_index == longer_array_length) {
            /*
             * Since shorter array is sorted in the ascending order,
             * and if the first index in the longer array whose value is greater
             * than or equal to the current iteated value in the shorter array,
             * we can break the loop since all the following uniterated values
             * won't be common value for sure.
             */
            break;
        }
        else if (
            (shorter_array_ptr[i])
            ==
            (longer_array_ptr[first_greater_than_or_equal_index])
        ) {
            return (shorter_array_ptr[i]);
        }
    }

    return -1;
}
