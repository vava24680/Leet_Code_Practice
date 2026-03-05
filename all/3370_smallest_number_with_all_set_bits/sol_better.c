int smallestNumber(int n) {
    int answer = 1;

    while (answer <= n) {
        answer <<= 1;
    }

    return answer - 1;
}
