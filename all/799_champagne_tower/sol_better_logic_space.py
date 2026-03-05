class Solution:
    def champagneTower(
        self,
        poured: int,
        query_row: int,
        query_glass: int
    ) -> float:
        current_row = [0] * (query_row + 1)
        current_row[0] = float(poured)

        for row_index in range(query_row):
            for column_index in reversed(range(row_index + 1)):
                if current_row[column_index] >= 1.0:
                    half_overflow_quantity = (
                        (current_row[column_index] - 1.0) / 2.0
                    )
                    current_row[column_index + 1] += half_overflow_quantity
                    current_row[column_index] = half_overflow_quantity
                else:
                    # No overflow case.
                    current_row[column_index] = 0.0

        if current_row[query_glass] >= 1.0:
            return 1.0

        return current_row[query_glass]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [1, 1, 1],
        [2, 1, 1],
        [100000009, 33, 17],
        [7, 3, 1],
        # [1000000000, 99, 99],
    ]

    for testcase in testcases_list:
        print(sol.champagneTower(*testcase))
