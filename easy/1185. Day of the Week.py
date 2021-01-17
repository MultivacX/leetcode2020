# 1185. Day of the Week
# https://leetcode.com/problems/day-of-the-week/

# Runtime: 60 ms, faster than 5.82% of Python3 online submissions for Day of the Week.
# Memory Usage: 14.3 MB, less than 56.72% of Python3 online submissions for Day of the Week.
    
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        l = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        return l[datetime.datetime(year, month, day, 0, 0, 0, 0).weekday()]