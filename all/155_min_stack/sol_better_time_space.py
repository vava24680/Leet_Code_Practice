class MinStack:
    def __init__(self):
        self._normal_stack = list()

        # Current minimum value stack tracks the minimum value when normal stack
        # has different number of elements.
        self._current_minimum_value_stack = list()

    def push(self, val: int) -> None:
        self._normal_stack.append(val)

        # Only push current new value to the minimum value stack if one the
        # following conditions is met:
        # 1. Current minimum value stack is empty.
        # 2. Current new value is less than or equal to the top value of the
        #    current minimum value stack.
        #
        # The reason we do this is to make sure the top value of the current
        # minimum value stack is the current minimum value among of the values
        # in the normal stack.
        if (
            (not self._current_minimum_value_stack)
            or
            (val <= ((self._current_minimum_value_stack)[-1]))
        ):
            self._current_minimum_value_stack.append(val)

    def pop(self) -> None:
        # Pop one item from the normal stack.
        popped_value = self._normal_stack.pop()

        # If current popped value is as the as the top value of the currnet
        # minimum value stack, we need to pop that value from that stack,
        # so that stack can keep tracking the minimum value correctly.
        if ((self._current_minimum_value_stack)[-1]) == popped_value:
            self._current_minimum_value_stack.pop()

    def top(self) -> int:
        return self._normal_stack[-1]

    def getMin(self) -> int:
        return self._current_minimum_value_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
