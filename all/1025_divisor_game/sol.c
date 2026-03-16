#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool divisorGame(int n) {
    /*
     * This array records if a person first gets an number, which is represented
     * by array index, will win or lose.
     */
    bool *player_wins_array_ptr = (
        (bool*)malloc(sizeof(*player_wins_array_ptr) * (n + 1))
    );
    bool result = false;

    if (NULL == player_wins_array_ptr) {
        return false;
    }

    player_wins_array_ptr[1] = false;

    for (int i = 2; i <= n; ++i) {
        player_wins_array_ptr[i] = false;

        for (int factor_1 = 1, factor_2; factor_1 <= (i >> 1) ; ++factor_1) {
            if ((i % factor_1)) {
                continue;
            }

            factor_2 = (i / factor_1);

            if (
                (false == player_wins_array_ptr[i - factor_1])
                ||
                (
                    (i != factor_2) /* Factor cannot be the original number itself. */
                    &&
                    (false == player_wins_array_ptr[i - factor_2])
                )
            ) {
                /*
                 * If there is factor such that Bob will lose if het gets after
                 * substraction, it means Alice can win if first get that
                 * number.
                 */
                player_wins_array_ptr[i] = true;

                break;
            }
        }
    }

    result = player_wins_array_ptr[n];

    free(player_wins_array_ptr);
    player_wins_array_ptr = NULL;

    return result;
}
