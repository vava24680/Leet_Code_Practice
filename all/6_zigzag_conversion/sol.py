class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if 1 == numRows:
            return s

        s_length = len(s)
        answer_characters_list = ['0'] * s_length
        max_read_index_steps = ((numRows << 1) - 2)
        write_index = 0

        for row_index in range(numRows):
            # Fill the characters of each row in the zigzag representation
            # into the answer characters list.
            read_index = row_index
            read_index_steps = max_read_index_steps - (row_index << 1)

            if 0 == read_index_steps:
                # If read index steps is 0, change it to maximum read index
                # steps.
                read_index_steps = max_read_index_steps

            while read_index < s_length:
                answer_characters_list[write_index] = s[read_index]

                # Update read index.
                read_index += read_index_steps

                write_index += 1

                # Update new read index steps.
                if max_read_index_steps != read_index_steps:
                    read_index_steps = max_read_index_steps - read_index_steps

        return ''.join(answer_characters_list)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['PAYPALISHIRING', 3],
        ['PAYPALISHIRING', 4],
        ['A', 1],
    ]

    for testcase in testcases_list:
        print(sol.convert(*testcase))
