#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    int position;
    int health;
    char direction;
    int original_index;
} RobotInfoST;

int positionCompareFunction(const void *p1, const void *p2) {
    const int position_1 = (((const RobotInfoST*)p1)->position);
    const int position_2 = (((const RobotInfoST*)p2)->position);

    return ((position_1 > position_2) - (position_1 < position_2));
}

int originalIndexCompareFunction(const void *p1, const void *p2) {
    const int original_index_1 = (((const RobotInfoST*)p1)->original_index);
    const int original_index_2 = (((const RobotInfoST*)p2)->original_index);

    return (
        (original_index_1 > original_index_2)
        -
        (original_index_1 < original_index_2)
    );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* survivedRobotsHealths(
    int* positions,
    int positionsSize,
    int* healths,
    int healthsSize,
    char* directions,
    int* returnSize
) {
    const int ROBOTS_COUNT = positionsSize;

    bool is_current_robot_alive = true;
    /* Use the original array as stack to save space. */
    int stack_next_available_index = 0;
    int *answer_array_ptr = NULL;
    RobotInfoST *robots_info_st_array_ptr = (
        (RobotInfoST*)malloc(sizeof(*robots_info_st_array_ptr) * ROBOTS_COUNT)
    );
    RobotInfoST *stack_top_robot_info_st_ptr = NULL;

    for (int i = 0; i < ROBOTS_COUNT; ++i) {
        ((robots_info_st_array_ptr[i]).position) = (positions[i]);
        ((robots_info_st_array_ptr[i]).health) = (healths[i]);
        ((robots_info_st_array_ptr[i]).direction) = (directions[i]);
        ((robots_info_st_array_ptr[i]).original_index) = i;
    }

    /* Sort all robots information by the position in the ascending order. */
    qsort(
        (void*)robots_info_st_array_ptr,
        ROBOTS_COUNT,
        sizeof(*robots_info_st_array_ptr),
        &positionCompareFunction
    );

    for (int i = 0; i < ROBOTS_COUNT; ++i) {
        /* Mark every current robot as alive first. */
        is_current_robot_alive = true;

        while (
            stack_next_available_index
            &&
            (
                ('L' == ((robots_info_st_array_ptr[i]).direction))
                &&
                (
                    'R'
                    ==
                    ((robots_info_st_array_ptr[stack_next_available_index - 1]).direction)
                )
            )
        ) {
            /* Current robot collide with the robot at the stack top. */

            /* Get the robot information at the stack top. */
            stack_top_robot_info_st_ptr = (
                &(robots_info_st_array_ptr[stack_next_available_index - 1])
            );

            if (
                ((robots_info_st_array_ptr[i]).health)
                >
                (stack_top_robot_info_st_ptr->health)
            ) {
                /*
                 * Current robot has more health points than the robot at the
                 * stack top.
                 */

                /* Decrease the current robot health points by 1. */
                --((robots_info_st_array_ptr[i]).health);

                /*
                 * Pop out the robot at the stack top by decreasing the stack
                 * next available index by 1.
                 */
                --stack_next_available_index;
            }
            else {
                /*
                 * Current robot does not have more health points than the robot
                 * at the stack top.
                 */
                if (
                    ((robots_info_st_array_ptr[i]).health)
                    <
                    (stack_top_robot_info_st_ptr->health)
                ) {
                    /*
                     * Current robot has less health points than the robot at
                     * the stack top.
                     */

                    /*
                     * Decrease the health points of the robot at the stack top
                     * by 1.
                     */
                    --(stack_top_robot_info_st_ptr->health);
                }
                else {
                    /*
                     * Current robot has same health points as the robot at the
                     * stack top.
                     */

                    /*
                     * Pop out the robot at the stack top by decreasing the stack
                     * next available index by 1.
                     */
                    --stack_next_available_index;
                }

                /* Mark current robot is not alive. */
                is_current_robot_alive = false;

                /*
                 * Break the while loop since we do not need to check if there
                 * is further collision.
                 */
                break;
            }
        }

        if (is_current_robot_alive) {
            /*
             * If current robot is still alive, push its information to the
             * stack.
             */
            if (stack_next_available_index != i) {
                robots_info_st_array_ptr[stack_next_available_index] = (
                    robots_info_st_array_ptr[i]
                );
            }

            ++stack_next_available_index;
        }
    }

    /*
     * Sort the remaining robots information in the stack by the original index
     * in the ascending order.
     */
    qsort(
        (void*)robots_info_st_array_ptr,
        stack_next_available_index,
        sizeof(*robots_info_st_array_ptr),
        &originalIndexCompareFunction
    );

    answer_array_ptr = (
        (int*)malloc(sizeof(*answer_array_ptr) * stack_next_available_index)
    );

    for (int i = 0; i < stack_next_available_index; ++i) {
        (answer_array_ptr[i]) = ((robots_info_st_array_ptr[i]).health);
    }

    (*returnSize) = stack_next_available_index;

    free(robots_info_st_array_ptr);
    robots_info_st_array_ptr = NULL;

    return answer_array_ptr;
}
