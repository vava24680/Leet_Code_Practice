class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        continuous_one_segments_count = 0
        previous_bit_character = '0'

        for c in s:
            if ('0' == previous_bit_character) and ('1' == c):
                continuous_one_segments_count += 1

                if continuous_one_segments_count > 1:
                    return False

            previous_bit_character = c

        return (1 == continuous_one_segments_count)


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['1001'],
        ['110'],
        ['1'],
    ]

    for testcase in testcases_list:
        print(sol.checkOnesSegment(*testcase))
