from collections import Counter
from typing import List


class UnionFindDS:
    def __init__(self, n: int):
        self._parents_list = [i for i in range(n)]

    def find(self, i: int) -> int:
        if i >= (len(self._parents_list)):
            return -1

        root = i

        while root != ((self._parents_list)[root]):
            root = ((self._parents_list)[root])

        # Do path compresion to make all the nodes that have the same ancestor
        # point to the ancestor directly.
        while i != ((self._parents_list)[i]):
            original_parent = ((self._parents_list)[i])
            self._parents_list[i] = root
            i = original_parent

        return root

    def union(self, i: int, j: int) -> None:
        root_of_i = self.find(i)
        root_of_j = self.find(j)

        if root_of_i == root_of_j:
            # Return if i and j are in the same group.
            return

        # i and j are not in the same group, make the root of the root of j
        # become i, so i and j can be in the same group.
        self._parents_list[root_of_j] = root_of_i


class Solution:
    def minimumHammingDistance(
        self,
        source: List[int],
        target: List[int],
        allowedSwaps: List[List[int]]
    ) -> int:
        minimum_hamming_distance = 0
        union_find_ds_instance = UnionFindDS(len(source))

        # Set union find data structure.
        for i, j in allowedSwaps:
            union_find_ds_instance.union(i, j)

        # For each group of indices, we need count what numbers are in each
        # group and their counts.
        group_and_numbers_counter_mapping_dict = {}

        for i in range(len(source)):
            root_of_i = union_find_ds_instance.find(i)

            if root_of_i not in group_and_numbers_counter_mapping_dict:
                group_and_numbers_counter_mapping_dict[root_of_i] = Counter()

            group_and_numbers_counter_mapping_dict[root_of_i][source[i]] += 1

        # Iterate the target list, check if current iterated number can be
        # fulfilled with a certain group of numbers in the source list.
        for index, value in enumerate(target):
            # Get the group of current iterated index.
            root_of_index = union_find_ds_instance.find(index)

            if not group_and_numbers_counter_mapping_dict[root_of_index][value]:
                # Increase minimum hamming distance by if current iterated
                # number cannot be fulfilled by current group of numbers.
                minimum_hamming_distance += 1
            else:
                # Decrease the corresponding number counter by 1 as a sign of
                # fulfillment.
                group_and_numbers_counter_mapping_dict[root_of_index][value] -= (
                    1
                )

        return minimum_hamming_distance


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[1, 2, 3, 4], [2, 1, 4, 5], [[0, 1], [2, 3]]],
        [[1, 2, 3, 4], [1, 3, 2, 4], []],
        [[5, 1, 2, 4, 3], [1, 5, 4, 2, 3], [[0, 4], [4, 2], [1, 3], [1, 4]]],
    ]

    for testcase in testcases_list:
        print(sol.minimumHammingDistance(*testcase))
