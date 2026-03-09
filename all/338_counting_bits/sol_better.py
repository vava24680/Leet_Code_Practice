from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        result = [0] * (n + 1)

        for i in range(1, n + 1):
            result[i] = result[i >> 1] + (i & 1)

        return result


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [2],
        [5],
    ]

    for testcase in testcases_list:
        print(sol.countBits(*testcase))
