class Solution:
    CLOSE_OPEN_BRACKETS_MAP = {
        ')': '(',
        ']': '[',
        '}': '{',
    }

    def checkValidClosingBracket(
        self,
        close_bracket_char: str,
        open_bracket_characters_stack
    ) -> bool:
        if not open_bracket_characters_stack:
            return False

        poped_open_bracket_character = open_bracket_characters_stack.pop()

        return (
            poped_open_bracket_character
            ==
            self.CLOSE_OPEN_BRACKETS_MAP.get(close_bracket_char)
        )

    def isValid(self, s: str) -> bool:
        open_bracket_characters_stack = list()

        for c in s:
            if ('(' == c) or ('[' == c) or ('{' == c):
                open_bracket_characters_stack.append(c)
            elif (
                not self.checkValidClosingBracket(
                    c,
                    open_bracket_characters_stack
                )
            ):
                return False

        return not open_bracket_characters_stack


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['()'],
        ['()[]{}'],
        ['(]'],
        ['([])'],
        ['([)]'],
    ]

    for testcase in testcases_list:
        print(sol.isValid(*testcase))
