class Solution:
    def divisorGame(self, n: int) -> bool:
        # This list record if a person first gets an number, which is
        # represented by list index, will win or lose.
        first_play_wins_list = [False] * (n + 1)

        for i in range(2, n + 1):
            for factor_1 in range(1, (i >> 1) + 1):
                factor_2, remainder = divmod(i, factor_1)

                if remainder:
                    continue

                if (
                    (not first_play_wins_list[i - factor_1])
                    or
                    (
                        (i != factor_2)
                        and
                        (not first_play_wins_list[i - factor_2])
                    )
                ):
                    # If there is factor such that Bob will lose if he gets
                    # after substraction, it means Alice can win if she first
                    # get that number.
                    first_play_wins_list[i] = True

                    break

        return first_play_wins_list[n]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [2],
        [3],
        [4],
    ]

    for testcase in testcases_list:
        print(sol.divisorGame(*testcase))
