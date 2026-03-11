#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int judge_number = -1;

    /*
     * The following array records every person's trust score.
     * If a person is trusted, his/her score increases by 1.
     * If a person trusts someone else, his/her score decreases by 1.
     */
    int *trust_scores_array_ptr = (int*)calloc(n + 1, sizeof(int));

    if (NULL == trust_scores_array_ptr) {
        return judge_number;
    }

    for (int i = 0; i < trustSize; ++i) {
        if (INT_MIN != trust_scores_array_ptr[trust[i][0]]) {
            /*
             * Decrease the trust score by 1 of the guy who trusts someone if
             * his/her trust score is not INT_MIN (this is to prevent underflow).
             */
            trust_scores_array_ptr[trust[i][0]]--;
        }

        /* Increase the trust score of the guy being trusted. */
        trust_scores_array_ptr[trust[i][1]]++;
    }

    for (int i = 1; i <= n; ++i) {
        /*
         * If there is a person whose trust score is (n - 1), that person is
         * secret judge.
         * His/her trust score is (n - 1), and there are n persons:
         * 1. Everyone except himself/herself trusts him/her.
         * 2. He/She does not trust anyone, so his/her trust score can be
         *    (n - 1).
         */
        if ((n - 1) == trust_scores_array_ptr[i]) {
            judge_number = i;

            break;
        }
    }

    free(trust_scores_array_ptr);
    trust_scores_array_ptr = NULL;

    return judge_number;
}
