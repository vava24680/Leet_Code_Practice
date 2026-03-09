from typing import List


class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        answer_characters_list = []

        for index, num in enumerate(nums):
            answer_characters_list.append(str(int(num[index]) ^ 1))

        return ''.join(answer_characters_list)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['01', '10']],
        [['00', '01']],
        [['111', '011', '001']],
    ]

    for testcase in testcases_list:
        print(sol.findDifferentBinaryString(*testcase))
