// 1118. Number of Days in a Month
// https://leetcode.com/problems/number-of-days-in-a-month/

// Runtime: 0 ms, faster than 100.00% of Swift online submissions for Number of Days in a Month.
// Memory Usage: 13.9 MB, less than 100.00% of Swift online submissions for Number of Days in a Month.

class Solution {
    static let days: [Int] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    func numberOfDays(_ Y: Int, _ M: Int) -> Int {
        if Y % 4 != 0 || M != 2 {
            return Solution.days[M - 1]
        } else if Y % 100 == 0 && Y % 400 != 0 {
            return Solution.days[1]
        } else {
            return Solution.days[1] + 1
        }
    }
}