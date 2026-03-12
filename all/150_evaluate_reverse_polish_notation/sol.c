#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int computation_result = 0;
    int stack_next_available_index = 0;
    int value_to_be_push_to_stack = 0;
    int operand_1 = 0, operand_2 = 0;

    int *operands_stack_array_ptr = (
        (int*)malloc(sizeof(*operands_stack_array_ptr) * tokensSize)
    );
    char *current_token_string_ptr = NULL;

    if (NULL == operands_stack_array_ptr) {
        return INT_MIN;
    }

    for (int token_index = 0; token_index < tokensSize; ++token_index) {
        current_token_string_ptr = tokens[token_index];

        if (
            (
                ((current_token_string_ptr[0]) < '0')
                ||
                ((current_token_string_ptr[0]) > '9')
            )
            &&
            ('\0' == (current_token_string_ptr[1]))
        ) {
            /*
             * If current token is an operator, we need to pop two operands
             * from the operands stack.
             */
            if (stack_next_available_index < 2) {
                computation_result = INT_MIN;

                goto FINAL_CLEANUP;
            }

            operand_1 = (
                operands_stack_array_ptr[stack_next_available_index - 2]
            );
            operand_2 = (
                operands_stack_array_ptr[stack_next_available_index - 1]
            );
            stack_next_available_index -= 2;

            switch(current_token_string_ptr[0]) {
                case '+':
                    value_to_be_push_to_stack = operand_1 + operand_2;

                    break;
                case '-':
                    value_to_be_push_to_stack = operand_1 - operand_2;

                    break;
                case '*':
                    value_to_be_push_to_stack = operand_1 * operand_2;

                    break;
                case '/':
                    value_to_be_push_to_stack = operand_1 / operand_2;

                    break;
                default:
                    break;
            }
        }
        else {
            value_to_be_push_to_stack = (
                (int)strtol(current_token_string_ptr, NULL, 10)
            );
        }

        if (stack_next_available_index >= tokensSize) {
            computation_result = INT_MIN;

            goto FINAL_CLEANUP;
        }

        /* Push new operand value to the operands stack. */
        operands_stack_array_ptr[stack_next_available_index] = (
            value_to_be_push_to_stack
        );
        ++stack_next_available_index;
    }

    computation_result = operands_stack_array_ptr[0];

FINAL_CLEANUP:
    free(operands_stack_array_ptr);
    operands_stack_array_ptr = NULL;

    return computation_result;
}
