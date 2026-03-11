int tribonacci(int n) {
    int current_tribonacci_number = 0;
    int previous_tribonacci_number = 0;
    int tribonacci_number_before_previous_one = 0;

    if (n < 3) {
        return n > 0 ? 1 : 0;
    }

    current_tribonacci_number = 1;
    previous_tribonacci_number = 1;
    tribonacci_number_before_previous_one = 0;

    for (int i = 3; i <= n; ++i) {
        int original_tribonacci_number = current_tribonacci_number;

        current_tribonacci_number += (
            previous_tribonacci_number + tribonacci_number_before_previous_one
        );

        tribonacci_number_before_previous_one = previous_tribonacci_number;
        previous_tribonacci_number = original_tribonacci_number;
    }

    return current_tribonacci_number;
}
