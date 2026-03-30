#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_VALUE (100000)
#define BITMAP_BASE_TYPE_BIT_LENGTH (64)
#define BITMAP_ARRAY_LENGTH ((((MAX_VALUE) + 1) + BITMAP_BASE_TYPE_BIT_LENGTH) / BITMAP_BASE_TYPE_BIT_LENGTH)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool test_bit_set_in_bitmap_array(
    uint64_t * const bitmap_array_ptr,
    const int bit
) {
    if (bit > MAX_VALUE) {
        return false;
    }

    return (
        bitmap_array_ptr[bit / BITMAP_BASE_TYPE_BIT_LENGTH]
        &
        (UINT64_C(1) << ((uint64_t)(bit % BITMAP_BASE_TYPE_BIT_LENGTH)))
    );
}

void set_bit_in_bitmap_array(uint64_t * const bitmap_array_ptr, const int bit) {
    if (bit > MAX_VALUE) {
        return;
    }

    bitmap_array_ptr[bit / BITMAP_BASE_TYPE_BIT_LENGTH] |= (
        UINT64_C(1)
        <<
        ((uint64_t)(bit % BITMAP_BASE_TYPE_BIT_LENGTH))
    );
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode dummy_head_node = {
        .val = 0,
        .next = head,
    };
    struct ListNode *current_node_ptr = head;
    struct ListNode *previous_node_ptr = &dummy_head_node;
    uint64_t nums_bitmap_array[BITMAP_ARRAY_LENGTH] = {0};

    for (int i = 0; i < numsSize; ++i) {
        set_bit_in_bitmap_array(&(nums_bitmap_array[0]), nums[i]);
    }

    while (NULL != current_node_ptr) {
        if (
            test_bit_set_in_bitmap_array(
                &(nums_bitmap_array[0]),
                current_node_ptr->val
            )
        ) {
            previous_node_ptr->next = current_node_ptr->next;
        }
        else {
            previous_node_ptr = current_node_ptr;
        }

        current_node_ptr = current_node_ptr->next;
    }

    return dummy_head_node.next;
}
