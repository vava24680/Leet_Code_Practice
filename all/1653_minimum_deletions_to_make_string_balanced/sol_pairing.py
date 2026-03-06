class Solution:
    def minimumDeletions(self, s: str) -> int:
        minimum_deletions_count = 0
        current_not_dealt_b_count = 0

        for c in s:
            if 'b' == c:
                current_not_dealt_b_count += 1
            elif ('a' == c) and current_not_dealt_b_count:
                current_not_dealt_b_count -= 1
                minimum_deletions_count += 1

        return minimum_deletions_count
