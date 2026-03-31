int findDuplicate(int* nums, int numsSize) {
    int slow_pointer = 0;
    int fast_pointer = 0;

    /*
     * Use the check if a linked list has ring algorithm to make slow pointer
     * and fast pointer point to the same node.
     */
    while (1) {
        slow_pointer = nums[slow_pointer];
        fast_pointer = nums[nums[fast_pointer]];

        if (slow_pointer == fast_pointer) {
            break;
        }
    }

    /* Make the slow pointer point to the head node. */
    slow_pointer = 0;

    /* Find the cycle start node. */
    while (slow_pointer != fast_pointer) {
        slow_pointer = nums[slow_pointer];
        fast_pointer = nums[fast_pointer];
    }

    return slow_pointer;
}
