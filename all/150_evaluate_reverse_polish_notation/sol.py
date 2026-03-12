from typing import List


OPERATORS_SET = {'+', '-', '*', '/'}


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Reuse the given tokens list as the operands stack to save space.
        stack_next_available_index = 0

        for token in tokens:
            if (1 == len(token)) and (token in OPERATORS_SET):
                # Pop two operands from the operands stack.
                if stack_next_available_index < 2:
                    return None

                operand_1 = tokens[stack_next_available_index - 2]
                operand_2 = tokens[stack_next_available_index - 1]
                stack_next_available_index -= 2

                if '+' == token:
                    value_to_be_pushback = operand_1 + operand_2
                elif '-' == token:
                    value_to_be_pushback = operand_1 - operand_2
                elif '*' == token:
                    value_to_be_pushback = operand_1 * operand_2
                else:
                    # Use int to do truncate toward zero.
                    value_to_be_pushback = int(operand_1 / operand_2)
                    # The following code is correct but it might be less
                    # efficient.

                    # value_to_be_pushback, remainder = divmod(
                    #     operand_1,
                    #     operand_2
                    # )

                    # # Python interger division is truncate toward lower,
                    # # we need manually convert the result to truncate toward
                    # # zero if quotient is negative and remainder is not 0.
                    # if (value_to_be_pushback < 0) and remainder:
                    #     value_to_be_pushback += 1
            else:
                value_to_be_pushback = int(token)

            # Push new operand value to the operands stack. */
            tokens[stack_next_available_index] = value_to_be_pushback
            stack_next_available_index += 1

        return tokens[0]


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [['2', '1', '+', '3', '*']],
        [['4', '13', '5', '/', '+']],
        [['10', '6', '9', '3', '+', '-11', '*', '/', '*', '17', '+', '5', '+']],
    ]

    for testcase in testcases_list:
        print(sol.evalRPN(*testcase))
