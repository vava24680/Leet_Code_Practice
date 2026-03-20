from typing import List


class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        minimum_absoulte_difference = float('inf')
        result_list = []

        # Sort the given array in the ascending order first.
        arr.sort()

        # Find the minimum absolute difference between any two elements in the
        # given array.
        for i in range(1, len(arr)):
            if (arr[i] - arr[i - 1]) < minimum_absoulte_difference:
                minimum_absoulte_difference = arr[i] - arr[i - 1]

        # Find all pairs of elements whose absolute difference is the
        # minimum absolute difference.
        for i in range(1, len(arr)):
            if (arr[i] - arr[i - 1]) == minimum_absoulte_difference:
                result_list.append([arr[i - 1], arr[i]])

        return result_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[4, 2, 1, 3]],
        [[1, 3, 6, 10, 15]],
        [[3, 8, -10, 23, 19, -4, -14, 27]],
    ]

    for testcase in testcases_list:
        print(sol.minimumAbsDifference(*testcase))
