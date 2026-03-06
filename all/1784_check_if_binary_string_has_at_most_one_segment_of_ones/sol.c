#include <stdbool.h>

typedef enum {
    CURRENT_IS_ZERO = 0,
    CURRENT_IS_ONE= 1,
} ParsingStateEnum;

bool checkOnesSegment(char* s) {
    ParsingStateEnum parsing_state = CURRENT_IS_ZERO;
    int continuous_one_segments_count = 0;

    for (int i = 0; '\0' != s[i]; ++i) {
        switch (parsing_state) {
            case CURRENT_IS_ZERO:
                if ('1' == s[i]) {
                    parsing_state = CURRENT_IS_ONE;
                    ++continuous_one_segments_count;

                    if (continuous_one_segments_count > 1) {
                        /*
                         * Early return if there is at least two continuos
                         * one segments.
                         */
                        return false;
                    }
                }

                break;
            case CURRENT_IS_ONE:
                if ('0' == s[i]) {
                    parsing_state = CURRENT_IS_ZERO;
                }

                break;
            default:
                break;
        }
    }

    return (1 == continuous_one_segments_count);
}
