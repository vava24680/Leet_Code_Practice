#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    char * answer_string_ptr = NULL;
    const char * short_one = NULL;
    const char * long_one = NULL;
    int a_string_length = strlen(a);
    int b_string_length = strlen(b);
    int shorter_string_length = 0;
    int longer_string_length = 0;
    int answer_string_length = 0;
    int carry_bit_value = 0;
    int sum, digits_num = 0;

    if (a_string_length <= b_string_length) {
        short_one = a;
        long_one = b;
        shorter_string_length = a_string_length;
        longer_string_length = b_string_length;
        digits_num = b_string_length;
    }
    else {
        short_one = b;
        long_one = a;
        shorter_string_length = b_string_length;
        longer_string_length = a_string_length;
        digits_num = a_string_length;
    }

    /* Plus 2 is for the last carry value and null terminator. */
    answer_string_ptr = malloc(sizeof(char) * (digits_num + 2));

    for (
        int shorter_string_index = (shorter_string_length - 1),
            longer_string_index = (longer_string_length - 1);
        shorter_string_index >= 0;
        --shorter_string_index, --longer_string_index, ++answer_string_length
    ) {
        sum = (
            carry_bit_value
            +
            ((int)(short_one[shorter_string_index] - '0'))
            +
            ((int)(long_one[longer_string_index] - '0'))
        );
        answer_string_ptr[answer_string_length] = ((char)((sum & 0x1) + '0'));
        carry_bit_value = sum >> 1;
    }

    for (
        int longer_string_index = (
            longer_string_length - shorter_string_length - 1
        );
        longer_string_index >= 0;
        --longer_string_index, ++answer_string_length
    ) {
        sum = carry_bit_value + (int)(long_one[longer_string_index] - '0');
        answer_string_ptr[answer_string_length] = (char)((sum & 1) + '0');
        carry_bit_value = sum >> 1;
    }

    if (carry_bit_value) {
        answer_string_ptr[answer_string_length] = '1';
        ++answer_string_length;
    }

    /* Reversed the answer string. */
    for (int i = 0; i < (answer_string_length >> 1); ++i) {
        char tmp = answer_string_ptr[i];
        answer_string_ptr[i] = answer_string_ptr[answer_string_length - 1 - i];
        answer_string_ptr[answer_string_length - 1 - i] = tmp;
    }

    answer_string_ptr[answer_string_length] = '\0';

    return answer_string_ptr;
}

void print_result(const char * const answer_string_ptr) {
    for (unsigned int i = 0; i < strlen(answer_string_ptr); ++i) {
        printf("%c", answer_string_ptr[i]);
    }

    printf("\n");
}

int main() {
    char * answer_string_ptr = NULL;

    answer_string_ptr = addBinary("11", "1");
    print_result(answer_string_ptr);
    free(answer_string_ptr);

    answer_string_ptr = addBinary("1010", "1011");
    print_result(answer_string_ptr);
    free(answer_string_ptr);

    answer_string_ptr = addBinary("10101", "1");
    print_result(answer_string_ptr);
    free(answer_string_ptr);
}
