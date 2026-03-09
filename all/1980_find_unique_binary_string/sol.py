from typing import List


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        numbers_set = set(int(num, 2) for num in nums)

        for minimum_not_shown_number in range(1 << (len(nums))):
            if minimum_not_shown_number not in numbers_set:
                break

        return f'{minimum_not_shown_number:0{len(nums)}b}'


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['01', '10']],
        [['00', '01']],
        [['111', '011', '001']],
    ]

    for testcase in testcases_list:
        print(sol.findDifferentBinaryString(*testcase))
