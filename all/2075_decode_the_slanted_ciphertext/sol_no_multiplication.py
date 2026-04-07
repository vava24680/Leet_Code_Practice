class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        ROWS_NUMBER = rows
        COLUMNS_NUMBER = (len(encodedText) // ROWS_NUMBER)

        characters_list = []

        for start_column_index in range(COLUMNS_NUMBER):
            row_index = 0
            column_index = start_column_index
            one_dimension_index = start_column_index

            while (row_index < ROWS_NUMBER) and (column_index < COLUMNS_NUMBER):
                characters_list.append(encodedText[one_dimension_index])

                one_dimension_index += (COLUMNS_NUMBER + 1)
                row_index += 1
                column_index += 1

        return ''.join(characters_list).rstrip()


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['ch   ie   pr', 3],
        ['iveo    eed   l te   olc', 4],
        ['coding', 1],
    ]

    for testcase in testcases_list:
        print(sol.decodeCiphertext(*testcase))
