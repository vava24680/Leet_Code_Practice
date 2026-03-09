int romanToInt(char* s) {
    int result = 0;
    char previous_roman_char = '0';

    for (unsigned int i = 0; i < strlen(s); ++i) {
        switch (s[i]) {
            case 'I':
                result += 1;

                break;
            case 'V':
                if ('I' == previous_roman_char) {
                    result -= 2;
                }

                result += 5;

                break;
            case 'X':
                if ('I' == previous_roman_char) {
                    result -= 2;
                }

                result += 10;

                break;
            case 'L':
                if ('X' == previous_roman_char) {
                    result -= 20;
                }

                result += 50;

                break;
            case 'C':
                if ('X' == previous_roman_char) {
                    result -= 20;
                }

                result += 100;

                break;
            case 'D':
                if ('C' == previous_roman_char) {
                    result -= 200;
                }

                result += 500;

                break;
            case 'M':
                if ('C' == previous_roman_char) {
                    result -= 200;
                }

                result += 1000;

                break;
            default:
                break;
        }

        previous_roman_char = s[i];
    }

    return result;
}
