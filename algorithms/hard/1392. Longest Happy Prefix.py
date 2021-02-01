# 1392. Longest Happy Prefix

# Runtime: 1296 ms, faster than 51.97% of Python3 online submissions for Longest Happy Prefix.
# Memory Usage: 15 MB, less than 100.00% of Python3 online submissions for Longest Happy Prefix.

class Solution:
    def longestPrefix(self, s: str) -> str:
        length = len(s)
        for i in range(1, length):
            if s[i:] == s[:length - i]:
                return s[i:]
        return ""