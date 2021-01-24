// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/

// Runtime: 20 ms, faster than 100.00% of Swift online submissions for Find the Highest Altitude.
// Memory Usage: 14 MB, less than 100.00% of Swift online submissions for Find the Highest Altitude.

class Solution {
    func largestAltitude(_ gain: [Int]) -> Int {
        var h = 0
        var ans = 0
        for i in gain {
            h += i
            ans = max(ans, h)
        }
        return ans
    }
}