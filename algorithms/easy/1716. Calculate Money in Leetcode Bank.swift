// 1716. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

// Runtime: 4 ms, faster than 59.52% of Swift online submissions for Calculate Money in Leetcode Bank.
// Memory Usage: 13.6 MB, less than 76.19% of Swift online submissions for Calculate Money in Leetcode Bank.

class Solution {
    func totalMoney(_ n: Int) -> Int {
        let k = n / 7
        let l = n % 7
        return k * (1 + 7) * 7 / 2 + 7 * (0 + k - 1) * k / 2 + (1 + l) * l / 2 + k * l
    }
}