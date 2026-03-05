class Solution:
    def smallestNumber(self, n: int) -> int:
        answer = 1

        while answer <= n:
            answer <<= 1

        return answer - 1
