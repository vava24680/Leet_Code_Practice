from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs_length = [len(s) for s in strs]
        common_prefix_length = 0
        continue_loop_flag = True

        while continue_loop_flag:
            for i in range(len(strs)):
                if (
                    (common_prefix_length >= strs_length[i])
                    or
                    (
                        strs[i][common_prefix_length]
                        !=
                        strs[0][common_prefix_length]
                    )
                ):
                    continue_loop_flag = False

                    break

            if continue_loop_flag:
                common_prefix_length += 1

        return strs[0][:common_prefix_length]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['flower', 'flow', 'flight']],
        [['dog', 'racecard', 'car']],
    ]

    for testcase in testcases_list:
        print(sol.longestCommonPrefix(*testcase))
