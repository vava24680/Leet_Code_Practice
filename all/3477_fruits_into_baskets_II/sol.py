from typing import List


class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        unplaced_fruits_number = 0
        # Record the minimum quantity that one kind of fruit cannot be placed.
        minimum_unplaced_fruit_quantity = float('inf')
        baskets_length = len(baskets)

        for fruit_quantity in fruits:
            if fruit_quantity >= minimum_unplaced_fruit_quantity:
                # If quantity of current fruit is greater than or equal to the
                # current minimum fruit quantity that cannot be placed,
                # the current fruit cannot be placed in any left baskets,
                # so just increase unplaced fruits number by 1 and continue to
                # next fruit.
                unplaced_fruits_number += 1

                continue

            for i in range(baskets_length):
                if (baskets[i] >= 0) and (baskets[i] >= fruit_quantity):
                    # Turn basket capacity number to -1 to denote this basket
                    # is used.
                    baskets[i] = -1

                    break
            else:
                # Increase unplaced fruits number by 1 if current fruit cannot
                # be placed in any left baskets.
                unplaced_fruits_number += 1

                if fruit_quantity < minimum_unplaced_fruit_quantity:
                    # If quantity of current fruit is less than the current
                    # minimum fruit quantity that cannot be placed, change
                    # the current minimum fruit quantity that cannot be placed
                    # to current fruit quantity.
                    minimum_unplaced_fruit_quantity = fruit_quantity

        return unplaced_fruits_number


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[4, 2, 5], [3, 5, 4]],
        [[3, 6, 1], [6, 4, 7]],
    ]

    for testcase in testcases_list:
        print(sol.numOfUnplacedFruits(*testcase))
