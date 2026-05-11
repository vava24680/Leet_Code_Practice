from typing import List


class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        answer_list = list()

        for num in nums:
            # Convert each number to string and add each digit in integer format
            # to answer list.
            for c in str(num):
                answer_list.append(int(c))

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[13, 25, 83, 77]],
        [[7, 1, 3, 9]],
    ]

    for testcase in testcases_list:
        print(sol.separateDigits(*testcase))
