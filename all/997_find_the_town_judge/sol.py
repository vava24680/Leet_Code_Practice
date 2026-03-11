from typing import List


class Solution:
    def findJudge(self, n: int, trust_pairs_list: List[List[int]]) -> int:
        # The following list records if a person has trusted anyone.
        trust_anyone_list = [False] * (n + 1)

        # The following array records how many times that a person is trusted.
        be_trusted_times_list = [0] * (n + 1)

        for trust_pair in trust_pairs_list:
            # Iterate the given trust array.
            trust_anyone_list[trust_pair[0]] = True
            be_trusted_times_list[trust_pair[1]] += 1

        for i in range(1, n + 1):
            if (
                ((n - 1) == be_trusted_times_list[i])
                and
                (not trust_anyone_list[i])
            ):
                return i

        return -1


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [2, [[1, 2]]],
        [3, [[1, 3], [2, 3]]],
        [3, [[1, 3], [2, 3], [3, 1]]],
    ]

    for testcase in testcases_list:
        print(sol.findJudge(*testcase))
