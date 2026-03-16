void duplicateZeros(int* arr, int arrSize) {
    int zeros_count = 0;
    int expected_write_start_index = 0;
    int write_count;

    for (int i = 0; i < arrSize; ++i) {
        if (0 == arr[i]) {
            ++zeros_count;
        }
    }

    expected_write_start_index = (arrSize + zeros_count - 1);

    for (int i = arrSize - 1; i >= 0; --i) {
        if (0 == arr[i]) {
            write_count = 2;
        }
        else {
            write_count = 1;
        }

        /*
         * Calculate the expected write start index for current iterated
         * element.
         */
        expected_write_start_index -= (write_count - 1);

        for (
            int j = 0;
            j < write_count && ((expected_write_start_index + j) < arrSize);
            ++j
        ) {
            arr[expected_write_start_index + j] = arr[i];
        }

        /* Update new expected write start index by subtracting by 1. */
        --expected_write_start_index;
    }
}
