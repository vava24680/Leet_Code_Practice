class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        string_length = len(s)

        for i in range(len(s) >> 1):
            s[i], s[string_length - 1 - i] = s[string_length - 1 - i], s[i]
