# 1360. Number of Days Between Two Dates
# https://leetcode.com/problems/number-of-days-between-two-dates/

# Runtime: 32 ms, faster than 54.53% of Python3 online submissions for Number of Days Between Two Dates.
# Memory Usage: 14 MB, less than 100.00% of Python3 online submissions for Number of Days Between Two Dates.

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return abs((date.fromisoformat(date1) - date.fromisoformat(date2)).days)