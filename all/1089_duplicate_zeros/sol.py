from typing import List


class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        arr_length = len(arr)
        zeros_count = 0

        for num in arr:
            if not num:
                zeros_count += 1

        expected_write_start_index = (arr_length + zeros_count - 1)

        for num in reversed(arr):
            if not num:
                write_count = 2
            else:
                write_count = 1

            # Calculate the expected write start index for current iterated
            # element.
            expected_write_start_index -= (write_count - 1)

            for i in range(write_count):
                if (expected_write_start_index + i) < arr_length:
                    arr[expected_write_start_index + i] = num

            # Update new expected write start index by subtracting by 1.
            expected_write_start_index -= 1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [1, 0, 2, 3, 0, 4, 5, 0],
        [1, 2, 3],
    ]

    for testcase in testcases_list:
        sol.duplicateZeros(testcase)

        print(testcase)
