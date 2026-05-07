void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int nums1_idx = m - 1;
    int nums2_idx = n - 1;
    int next_idx = m + n - 1;

    /* Start from the end to put elements. */
    while ((nums1_idx >= 0) && (nums2_idx >= 0)) {
        if (nums1[nums1_idx] >= nums2[nums2_idx]) {
            nums1[next_idx] = nums1[nums1_idx];
            --nums1_idx;
        }
        else {
            nums1[next_idx] = nums2[nums2_idx];
            --nums2_idx;
        }

        --next_idx;
    }

    /*
     * If nums2 idx is equal or greater than 0, it means there is at least
     * one element is not put into nums1, use simple while loop to put those
     * elements to nums1.
     */
    while (nums2_idx >= 0) {
        nums1[next_idx] = nums2[nums2_idx];
        --next_idx;
        --nums2_idx;
    }
}
