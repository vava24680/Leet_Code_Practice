class Solution:
    def champagneTower(
        self,
        poured: int,
        query_row: int,
        query_glass: int
    ) -> float:
        next_row = [float(poured)] * (query_row + 1 + 1)

        for row_index in range(query_row + 1):
            current_row, next_row = next_row, [0] * (query_row + 1 + 1)

            for column_index in range(row_index + 1):
                if current_row[column_index] >= 1.0:
                    next_row[column_index] += (
                        (current_row[column_index] - 1.0) / 2.0
                    )
                    next_row[column_index + 1] += (
                        (current_row[column_index] - 1.0) / 2.0
                    )
                    current_row[column_index] = 1.0

        return current_row[query_glass]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [1, 1, 1],
        [2, 1, 1],
        [100000009, 33, 17],
        [7, 3, 1],
        [1000000000, 99, 99],
    ]

    for testcase in testcases_list:
        print(sol.champagneTower(*testcase))
