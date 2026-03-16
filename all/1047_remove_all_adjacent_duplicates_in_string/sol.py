class Solution:
    def removeDuplicates(self, s: str) -> str:
        # Use characters list as stack.
        characters_list = list(s)
        stack_next_available_index = 0

        for character in characters_list:
            if (
                (not stack_next_available_index)
                or
                (
                    characters_list[stack_next_available_index - 1]
                    !=
                    character
                )
            ):
                # Push current iterated character to stack if stack is currently
                # empty or current iterated character is different from the
                # character at the stack top.
                characters_list[stack_next_available_index] = character
                stack_next_available_index += 1
            else:
                # Pop the top character from the stack if current iterated
                # character is as same as it.
                stack_next_available_index -= 1

        return ''.join(characters_list[:stack_next_available_index])


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        ['abbaca'],
        ['azxxzy'],
        ['aaaaaaaaaaaaaaaaaaaaaaaaa'],
    ]

    for testcase in testcases_list:
        print(sol.removeDuplicates(*testcase))
