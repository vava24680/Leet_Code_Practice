from typing import List


class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        result_list = [0] * (len(s) + 1)
        current_lowest_candidate_number = 0
        current_greatest_candidate_number = len(s)

        for index, c in enumerate(s):
            if 'D' == c:
                # As 'D' means current element must be greater than the next
                # element, but we still don't know next element and its
                # relationship with next two element.
                # To play safe and retain flexibiliy, we use current greatest
                # candidate number as current element.
                result_list[index] = current_greatest_candidate_number

                # Update new current greatest candidate number. */
                current_greatest_candidate_number -= 1
            elif 'I' == c:
                # As 'I' means current element must be smaller than the next
                # element, but we still don't know next element and its
                # relationship with next two element.
                # To play safe and retain flexibiliy, we use current lowest
                # candidate number as current element.
                result_list[index] = current_lowest_candidate_number

                # Update new current lowest candidate number. */
                current_lowest_candidate_number += 1

        # After iterating the given string `s`, the current greatest candidate
        # number and the current lowest candidate number should be the same,
        # and that number will be the last number to fill in the result array.
        result_list[-1] = current_greatest_candidate_number

        return result_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['IDID'],
        ['III'],
        ['DDI'],
    ]

    for testcase in testcases_list:
        print(sol.diStringMatch(*testcase))
