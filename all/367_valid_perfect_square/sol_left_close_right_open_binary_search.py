class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        # In the range of 1 to num, find the minimum k such that:
        # 1. 1 <= k <= num.
        # 2. k * k >= num.
        #
        # After k is found, check if k * k equals to num.
        left_value = 1
        right_value = num

        while left_value < right_value:
            middle_value = (left_value + ((right_value - left_value) >> 1))
            middle_square_value = (middle_value ** 2)

            if num > middle_square_value:
                left_value = middle_value + 1
            else:
                right_value = middle_value

        return (num == (left_value ** 2))


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [16],
        [14],
        [1],
        [2],
        [3],
        [4],
        [75478478],
    ]

    for testcase in testcases_list:
        print(sol.isPerfectSquare(*testcase))
