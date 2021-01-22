// 1085. Sum of Digits in the Minimum Number
// https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/

// Runtime: 4 ms, faster than 100.00% of Swift online submissions for Sum of Digits in the Minimum Number.
// Memory Usage: 13.8 MB, less than 44.44% of Swift online submissions for Sum of Digits in the Minimum Number.

class Solution {
    func sumOfDigits(_ A: [Int]) -> Int {
        var minNum = A.min()!
        var sum = 0
        while minNum > 0 {
            sum += minNum % 10
            minNum /= 10
        }
        return sum & 1 != 0 ? 0 : 1
    }
}