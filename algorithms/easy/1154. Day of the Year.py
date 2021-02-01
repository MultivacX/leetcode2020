# 1154. Day of the Year
# https://leetcode.com/problems/day-of-the-year/

# Runtime: 32 ms, faster than 46.51% of Python3 online submissions for Day of the Year.
# Memory Usage: 14.2 MB, less than 99.74% of Python3 online submissions for Day of the Year.

class Solution:
    def dayOfYear(self, d: str) -> int:
        return (date.fromisoformat(d) - date.fromisoformat(d.split('-')[0] + '-01-01')).days + 1