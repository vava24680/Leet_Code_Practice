#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int judge_number = -1;

    /* The following array indicates if a person has trusted anyone. */
    bool *trust_anyone_array_ptr = (
        (bool*)(calloc(n + 1, sizeof(*trust_anyone_array_ptr)))
    );

    /* The following array records how many times that a person is trusted. */
    int *be_trusted_times_array_ptr = (
        (int*)(calloc(n + 1, sizeof(*be_trusted_times_array_ptr)))
    );

    for (int i = 0; i < trustSize; ++i) {
        /* Iterate the given trust array. */
        trust_anyone_array_ptr[trust[i][0]] = true;
        ++be_trusted_times_array_ptr[trust[i][1]];
    }

    for (int i = 1; i <= n; ++i) {
        if (
            ((n - 1) == be_trusted_times_array_ptr[i])
            &&
            (false == trust_anyone_array_ptr[i])
        ) {
            /*
             * If a guy whose trusted times is (n - 1) and that guy never trust
             * anyone, that guy is a judge.
             */
            judge_number = i;

            break;
        }
    }

    free(trust_anyone_array_ptr);
    trust_anyone_array_ptr = NULL;

    free(be_trusted_times_array_ptr);
    be_trusted_times_array_ptr = NULL;

    return judge_number;
}
