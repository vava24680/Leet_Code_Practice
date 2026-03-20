#include <limits.h>

int numOfUnplacedFruits(
    int* fruits,
    int fruitsSize,
    int* baskets,
    int basketsSize
) {
    int unplaced_fruits_number = 0;
    int minimum_unplaced_fruit_quantity = INT_MAX;

    for (int i = 0; i < fruitsSize; ++i) {
        int j = 0;

        if (fruits[i] >= minimum_unplaced_fruit_quantity) {
            /*
             * If quantity of current fruit is greater than or equal to the
             * current minimum fruit quantity that cannot be placed,
             * the current fruit cannot be placed in any left baskets,
             * so just increase unplaced fruits number by 1 and continue to
             * next fruit.
             */
            ++unplaced_fruits_number;

            continue;
        }

        for (j = 0; j < basketsSize; ++j) {
            if ((baskets[j] >= 0) && (baskets[j] >= fruits[i])) {
                /*
                 * Turn basket capacity number to -1 to denote this basket
                 * is used.
                 */
                baskets[j] = (-1);

                break;
            }
        }

        if (basketsSize == j) {
            /*
             * Increase unplaced fruits number by 1 if current fruit cannot be
             * placed in any left baskets.
             */
            ++unplaced_fruits_number;

            if (fruits[i] < minimum_unplaced_fruit_quantity) {
                /*
                 * If quantity of current fruit is less than the current minimum
                 * fruit quantity that cannot be placed, change the current
                 * minimum fruit quantity that cannot be placed to current
                 * fruit quantity.
                 */
                minimum_unplaced_fruit_quantity = fruits[i];
            }
        }
    }

    return unplaced_fruits_number;
}
