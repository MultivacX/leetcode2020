# 1507. Reformat Date
# https://leetcode.com/problems/reformat-date/

# Runtime: 28 ms, faster than 71.37% of Python3 online submissions for Reformat Date.
# Memory Usage: 14.2 MB, less than 27.89% of Python3 online submissions for Reformat Date.
    
class Solution:
    def reformatDate(self, date: str) -> str:
        month = {"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}
        a = date.split()
        d = a[0].replace('st', '').replace('nd', '').replace('rd', '').replace('th', '')
        if len(d) == 1:
            d = '0' + d
        return a[2] + '-' + month[a[1]] + '-' + d