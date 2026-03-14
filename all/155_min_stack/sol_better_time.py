class MinStack:
    def __init__(self):
        self._normal_stack = list()
        # Current minimum value stack is has the same length as the normal
        # stack, it tracks the minimum value when normal stack has different
        # number of elements.
        self._current_minimum_value_stack = list()

    def push(self, val: int) -> None:
        self._normal_stack.append(val)

        # Assume current new value is the current minimum value first.
        current_minimum_value = val

        if (
            self._current_minimum_value_stack
            and
            (self._current_minimum_value_stack[-1] < current_minimum_value)
        ):
            # Change current minimum value to the top value of the current
            # minimum value stack if it is less than current new value.
            current_minimum_value = self._current_minimum_value_stack[-1]

        # Push the real current minimum value to the current minimum value
        # stack.
        self._current_minimum_value_stack.append(current_minimum_value)

    def pop(self) -> None:
        # Pop one item from the normal stack and current minimum value stack
        # to retain synchronization between those two stacks.
        self._normal_stack.pop()
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
