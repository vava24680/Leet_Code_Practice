class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n > 0 else 0

        current_tribonacci_number = 1
        previous_tribonacci_number = 1
        tribonacci_number_before_previous_one = 0

        for _ in range(3, n + 1):
            original_tribonacci_number = current_tribonacci_number
            current_tribonacci_number += (
                previous_tribonacci_number
                + tribonacci_number_before_previous_one
            )

            tribonacci_number_before_previous_one = previous_tribonacci_number
            previous_tribonacci_number = original_tribonacci_number

        return current_tribonacci_number


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [4],
        [25],
    ]

    for testcase in testcases_list:
        print(sol.tribonacci(*testcase))
