class Solution:
    def smallestNumber(self, n: int) -> int:
        answer = 0

        while n:
            answer <<= 1
            answer |= 1
            n >>= 1

        return answer
