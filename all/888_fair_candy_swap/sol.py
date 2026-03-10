from typing import List


class Solution:
    def fairCandySwap(
        self,
        aliceSizes: List[int],
        bobSizes: List[int]
    ) -> List[int]:
        alice_total_candies_number = sum(aliceSizes)
        bob_total_candies_number = sum(bobSizes)
        result_list = []

        for alice_candy_number_in_current_box in aliceSizes:
            for bob_candy_number_in_current_box in bobSizes:
                if (
                    (
                        alice_total_candies_number
                        -
                        (alice_candy_number_in_current_box << 1)
                    )
                    ==
                    (
                        bob_total_candies_number
                        -
                        (bob_candy_number_in_current_box << 1)
                    )
                ):
                    result_list.append(alice_candy_number_in_current_box)
                    result_list.append(bob_candy_number_in_current_box)

                    break

            if result_list:
                break

        return result_list


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 1], [2, 2]],
        [[1, 2], [2, 3]],
        [[2], [1, 3]],
    ]

    for testcase in testcases_list:
        print(sol.fairCandySwap(*testcase))
