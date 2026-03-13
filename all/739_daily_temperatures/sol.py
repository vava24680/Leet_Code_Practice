from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer_list = [0] * len(temperatures)
        indices_stack = list()

        for current_index, temperature in enumerate(temperatures):
            while (
                indices_stack
                and
                (temperature > temperatures[indices_stack[-1]])
            ):
                # Pop out the index if current iterated temperature is larger
                # than the temperature indexed by the popped out index.
                # The temperature indexed by the popped out index has the
                # next larger temperature which is the current temperature,
                # so we can set answer for it.
                popped_index = indices_stack.pop()

                # Set answer for the temperature indexed by the popped out index.
                answer_list[popped_index] = current_index - popped_index

            # Add current iterated index to the indices stack since current
            # iterated temperature still does not have the next larger
            # temperature.
            indices_stack.append(current_index)

        return answer_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[73, 74, 75, 71, 69, 72, 76, 73]],
        [[30, 40, 50, 60]],
        [[30, 60, 90]],
    ]

    for testcase in testcases_list:
        print(sol.dailyTemperatures(*testcase))
