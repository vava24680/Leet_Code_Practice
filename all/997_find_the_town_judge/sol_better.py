from typing import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # The following array records every person's trust score.
        # If a person is trusted, his/her score increases by 1.
        # If a person trusts someone else, his/her score decreases by 1.
        trust_scores_list = [0] * (n + 1)

        for trust_person_label, trusted_person_label in trust:
            trust_scores_list[trust_person_label] -= 1
            trust_scores_list[trusted_person_label] += 1

        for i in range(1, n + 1):
            # If there is a person whose trust score is (n - 1), that person
            # is secret judge.
            # Its trust score is (n - 1), and there are n persons:
            # 1. Everyone except himself/herself trusts him/her.
            # 2. He/She does not trust anyone, so his/her trust score can be
            #    (n - 1).
            if (n - 1) == trust_scores_list[i]:
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
