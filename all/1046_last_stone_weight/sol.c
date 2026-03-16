typedef struct HeapStruct {
    int *array_ptr;
    int size;
    int capacity;
} HeapST;

static inline void swapTwoIntegers(int * const e1, int * const e2) {
    int tmp = (*e1);

    (*e1) = (*e2);
    (*e2) = tmp;
}

void bubbleUpMaxHeap(HeapST * const heap_st_ptr) {
    int current_node_index = (heap_st_ptr->size) - 1;
    int parent_node_index = (current_node_index - 1) >> 1;

    while (
        (current_node_index > 0)
        &&
        (
            (heap_st_ptr->array_ptr)[current_node_index]
            >
            (heap_st_ptr->array_ptr)[parent_node_index]
        )
    ) {
        swapTwoIntegers(
            &((heap_st_ptr->array_ptr)[current_node_index]),
            &((heap_st_ptr->array_ptr)[parent_node_index])
        );

        current_node_index = parent_node_index;
        parent_node_index = (current_node_index - 1) >> 1;
    }
}

void bubbleDownMaxHeap(HeapST * const heap_st_ptr, int start_index) {
    int current_node_index = start_index;
    int left_child_node_index = 0;
    int right_child_node_index = 0;
    int largest_node_index = -1;

    while (current_node_index < ((heap_st_ptr->size) >> 1)) {
        largest_node_index = current_node_index;
        left_child_node_index = (current_node_index << 1) + 1;
        right_child_node_index = (current_node_index << 1) + 2;

        if (
            (left_child_node_index < (heap_st_ptr->size))
            &&
            (
                (heap_st_ptr->array_ptr)[left_child_node_index]
                >
                (heap_st_ptr->array_ptr)[largest_node_index]
            )
        ) {
            largest_node_index = left_child_node_index;
        }

        if (
            (right_child_node_index < (heap_st_ptr->size))
            &&
            (
                (heap_st_ptr->array_ptr)[right_child_node_index]
                >
                (heap_st_ptr->array_ptr)[largest_node_index]
            )
        ) {
            largest_node_index = right_child_node_index;
        }

        if (largest_node_index == current_node_index) {
            break;
        }

        swapTwoIntegers(
            &((heap_st_ptr->array_ptr)[current_node_index]),
            &((heap_st_ptr->array_ptr)[largest_node_index])
        );

        current_node_index = largest_node_index;
    }
}

void pushToMaxHeap(HeapST * const heap_st_ptr, const int value) {
    (heap_st_ptr->array_ptr)[(heap_st_ptr->size)++] = value;

    bubbleUpMaxHeap(heap_st_ptr);
}

int popFromMaxHeap(HeapST * const heap_st_ptr) {
    int poped_element = 0;

    if (0 == (heap_st_ptr->size)) {
        return -1;
    }

    poped_element = (heap_st_ptr->array_ptr)[0];
    (heap_st_ptr->array_ptr)[0] = \
        (heap_st_ptr->array_ptr)[(heap_st_ptr->size) - 1];
    --(heap_st_ptr->size);

    bubbleDownMaxHeap(heap_st_ptr, 0);

    return poped_element;
}

void constructMaxHeap(HeapST * const heap_st_ptr) {
    for (int i = ((heap_st_ptr->size) >> 1) - 1; i >= 0; --i) {
        bubbleDownMaxHeap(heap_st_ptr, i);
    }
}

int lastStoneWeight(int* stones, int stonesSize) {
    HeapST heap_st = {
        .array_ptr = stones,
        .size = stonesSize,
        .capacity = stonesSize,
    };
    int first_heavy_stone = 0, second_heavy_stone = 0;

    /* Construct a max heap. */
    constructMaxHeap(&heap_st);

    while ((heap_st.size) >= 2) {
        first_heavy_stone = popFromMaxHeap(&heap_st);
        second_heavy_stone = popFromMaxHeap(&heap_st);

        if (first_heavy_stone > second_heavy_stone) {
            pushToMaxHeap(&heap_st, first_heavy_stone - second_heavy_stone);
        }
    }

    return ((1 == (heap_st.size)) ? heap_st.array_ptr[0] : 0);
}
