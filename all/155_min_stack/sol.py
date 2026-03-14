class MinStack:
    def __init__(self):
        self._normal_stack = list()
        self._min_stack = list()

    def push(self, val: int) -> None:
        tmp_stack = list()

        while self._min_stack and (val > (self._min_stack[-1])):
            tmp_stack.append(self._min_stack.pop())

        self._min_stack.append(val)

        while tmp_stack:
            self._min_stack.append(tmp_stack.pop())

        self._normal_stack.append(val)

    def pop(self) -> None:
        popped_value = self._normal_stack.pop()
        tmp_stack = list()

        while (self._min_stack) and (popped_value > (self._min_stack[-1])):
            tmp_stack.append(self._min_stack.pop())

        self._min_stack.pop()

        while tmp_stack:
            self._min_stack.append(tmp_stack.pop())

    def top(self) -> int:
        return self._normal_stack[-1]

    def getMin(self) -> int:
        return self._min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
