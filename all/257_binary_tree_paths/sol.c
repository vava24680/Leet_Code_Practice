#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **strings_array_ptr;
    int array_length;
    int next_available_index;
} AnswerST;

typedef struct {
    int *array_ptr;
    int array_length;
    int next_available_index;
} StackST;

static int computeDigitsNumber(const int x) {
    int digits_number = ((x <= 0) ? 1 : 0);
    long long _x = llabs((long long)x);

    while (0LL != _x) {
        ++digits_number;
        _x /= 10LL;
    }

    return digits_number;
}

static bool pushStack(StackST * const nodes_values_stack_st_ptr, const int x) {
    if (NULL == nodes_values_stack_st_ptr) {
        return false;
    }

    int *tmp_array_ptr = NULL;
    int new_array_length = 0;

    if (
        (nodes_values_stack_st_ptr->next_available_index)
        >=
        (nodes_values_stack_st_ptr->array_length)
    ) {
        if (0 == (nodes_values_stack_st_ptr->array_length)) {
            new_array_length = 4;
        }
        else {
            new_array_length = ((nodes_values_stack_st_ptr->array_length) << 1);
        }

        tmp_array_ptr = (
            (int*)realloc(
                nodes_values_stack_st_ptr->array_ptr,
                sizeof(*(nodes_values_stack_st_ptr->array_ptr))
                *
                new_array_length
            )
        );

        if (NULL == tmp_array_ptr) {
            return false;
        }

        (nodes_values_stack_st_ptr->array_ptr) = tmp_array_ptr;
        (nodes_values_stack_st_ptr->array_length) = new_array_length;
    }

    nodes_values_stack_st_ptr->array_ptr[
        nodes_values_stack_st_ptr->next_available_index
    ] = x;

    ++(nodes_values_stack_st_ptr->next_available_index);

    return true;
}

static bool popStack(
    StackST * const nodes_values_stack_st_ptr,
    int * const poped_value_ptr
) {
    if (
        (NULL == nodes_values_stack_st_ptr)
        ||
        (0 == (nodes_values_stack_st_ptr->next_available_index))
    ) {
        return false;
    }

    (*poped_value_ptr) = (nodes_values_stack_st_ptr->array_ptr)[
        (nodes_values_stack_st_ptr->next_available_index) - 1
    ];

    (--(nodes_values_stack_st_ptr->next_available_index));

    return true;
}

static char* constructPathString(const StackST * const nodes_values_stack_st_ptr) {
    char *path_string_ptr = NULL, *walking_ptr = NULL;
    int answer_string_length = 0;
    int printed_characters_count = 0;

    /*
     * Accumulate number of slots we need to store all the nodes' values in a
     * path string.
     */
    for (int i = 0; i < nodes_values_stack_st_ptr->next_available_index; ++i) {
        answer_string_length += computeDigitsNumber(
            (nodes_values_stack_st_ptr->array_ptr)[i]
        );
    }

    /* Accumulate number of slot we need to store all '->' in a path string. */
    answer_string_length += (
        ((nodes_values_stack_st_ptr->next_available_index) - 1) << 1
    );

    /* Allocate space for path string. */
    path_string_ptr = (char*)malloc(sizeof(char) * (answer_string_length + 1));
    walking_ptr = path_string_ptr;

    /* Add the value of the first node in the current path to the path string. */
    printed_characters_count = sprintf(
        walking_ptr, "%d", (nodes_values_stack_st_ptr->array_ptr)[0]
    );
    walking_ptr += printed_characters_count;

    for (
        int i = 1;
        i < (nodes_values_stack_st_ptr->next_available_index);
        ++i
    ) {
        /*
         * Add '->' and the values of the nodes except the first one in the
         * current path to the path string.
         */
        (*(walking_ptr++)) = '-';
        (*(walking_ptr++)) = '>';

        printed_characters_count = sprintf(
            walking_ptr,
            "%d",
            (nodes_values_stack_st_ptr->array_ptr)[i]
        );

        walking_ptr += printed_characters_count;
    }

    path_string_ptr[answer_string_length] = '\0';

    return path_string_ptr;
}

static bool addPathToAnswerStruct(
    AnswerST * const answer_struct_ptr,
    const StackST * const nodes_values_stack_st_ptr
) {
    int new_array_size = 0;
    char *path_string_ptr = constructPathString(nodes_values_stack_st_ptr);
    char **tmp_strings_array_ptr = NULL;

    if (
        (answer_struct_ptr->next_available_index)
        >=
        (answer_struct_ptr->array_length)
    ) {
        if (0 == (answer_struct_ptr->array_length)) {
            new_array_size = 4;
        }
        else {
            new_array_size = ((answer_struct_ptr->array_length) << 1);
        }

        tmp_strings_array_ptr = (
            (char**)realloc(
                answer_struct_ptr->strings_array_ptr,
                sizeof(*(answer_struct_ptr->strings_array_ptr)) * new_array_size
            )
        );

        if (NULL == tmp_strings_array_ptr) {
            return false;
        }

        (answer_struct_ptr->strings_array_ptr) = tmp_strings_array_ptr;
        (answer_struct_ptr->array_length) = new_array_size;
    }

    (answer_struct_ptr->strings_array_ptr)[
        answer_struct_ptr->next_available_index
    ] = path_string_ptr;

    ++(answer_struct_ptr->next_available_index);

    return true;
}

static void preorderTraverseTree(
    AnswerST * const answer_struct_ptr,
    StackST * const nodes_values_stack_st_ptr,
    const struct TreeNode * const root
) {
    if (NULL == root) {
        return;
    }

    int poped_value = 0;

    /* Push current node's value in the nodes' values stack. */
    pushStack(nodes_values_stack_st_ptr, root->val);

    if ((NULL == (root->left)) && (NULL == (root->right))) {
        /*
         * Current node is a leaf node, and current traverse path to the answer
         * list.
         */
        addPathToAnswerStruct(answer_struct_ptr, nodes_values_stack_st_ptr);
    }
    else {
        /*
         * Current node is not a leaf node, continue traversing the left subtree
         * and the right subtree.
         */
        preorderTraverseTree(
            answer_struct_ptr,
            nodes_values_stack_st_ptr,
            root->left
        );
        preorderTraverseTree(
            answer_struct_ptr,
            nodes_values_stack_st_ptr,
            root->right
        );
    }

    /*
     * Pop current node's value from nodes' values stack.
     * This is backtracking.
     */
    popStack(nodes_values_stack_st_ptr, &poped_value);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    AnswerST answer_struct = {
        .strings_array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };
    StackST nodes_values_stack_st = {
        .array_ptr = NULL,
        .array_length = 0,
        .next_available_index = 0,
    };

    preorderTraverseTree(&answer_struct, &nodes_values_stack_st, root);

    free(nodes_values_stack_st.array_ptr);
    (nodes_values_stack_st.array_ptr) = NULL;

    (*returnSize) = (answer_struct.next_available_index);

    return answer_struct.strings_array_ptr;
}
