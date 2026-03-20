from typing import List


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        first_point_x_index = coordinates[0][0]
        first_point_y_index = coordinates[0][1]
        second_point_x_index = coordinates[1][0]
        second_point_y_index = coordinates[1][1]

        for i in range(2, len(coordinates)):
            current_x_index = coordinates[i][0]
            current_y_index = coordinates[i][1]

            if (
                (
                    (current_y_index - first_point_y_index)
                    *
                    (current_x_index - second_point_x_index)
                )
                !=
                (
                    (current_y_index - second_point_y_index)
                    *
                    (current_x_index - first_point_x_index)
                )
            ):
                return False

        return True


if '__main__' == __name__:
    sol = Solution()
    testcases_list = [
        [[[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]],
        [[[1, 1], [2, 2], [3, 4], [4, 5], [5, 6], [7, 7]]],
    ]

    for testcase in testcases_list:
        print(sol.checkStraightLine(*testcase))
