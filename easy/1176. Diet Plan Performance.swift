// 1176. Diet Plan Performance
// https://leetcode.com/problems/diet-plan-performance/

// Runtime: 292 ms, faster than 50.00% of Swift online submissions for Diet Plan Performance.
// Memory Usage: 17.1 MB, less than 66.67% of Swift online submissions for Diet Plan Performance.

class Solution {
    func dietPlanPerformance(_ calories: [Int], _ k: Int, _ lower: Int, _ upper: Int) -> Int {
        var ans = 0
        var sum = 0
        for i in 0..<calories.count {
            sum += calories[i]
            if i + 1 < k { continue }
            if i >= k { sum -= calories[i - k] }
            if sum < lower { ans -= 1 }
            else if sum > upper { ans += 1 }
        }
        return ans
    }
}