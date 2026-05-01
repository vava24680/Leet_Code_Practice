int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int index_1 = 0, index_2 = 0;

    while ((index_1 < nums1Size) && (index_2 < nums2Size)) {
        if ((nums1[index_1]) == (nums2[index_2])) {
            return nums1[index_1];
        }
        else if ((nums1[index_1]) > (nums2[index_2])) {
            /*
             * Since nums1[index_1] is greater than nums2[index_2] and nums2 is
             * sorted in ascending order, there won't any value in the
             * nums2[:index_2 + 1] that can be equal to or greater than
             * nums1[index_1].
             * So increase index_2 by 1 for possible larger value to be checked
             * with nums1[index_1].
             */
            ++index_2;
        }
        else {
            /*
             * Since nums1[index_1] is smaller than nums2[index_2] and nums1 is
             * sorted in ascending order, there won't any value in the
             * nums1[:index_1 + 1] that can be equal to or greater than
             * nums2[index_2].
             * So increase index_1 by 1 for possible larger value to be checked
             * with nums2[index_2].
             */
            ++index_1;
        }
    }

    return -1;
}
