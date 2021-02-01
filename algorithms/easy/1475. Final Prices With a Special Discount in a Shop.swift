// 1475. Final Prices With a Special Discount in a Shop
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// Runtime: 24 ms, faster than 94.12% of Swift online submissions for Final Prices With a Special Discount in a Shop.
// Memory Usage: 13.9 MB, less than 82.35% of Swift online submissions for Final Prices With a Special Discount in a Shop.

class Solution {
    func finalPrices(_ prices: [Int]) -> [Int] {
        var ans = prices
        for i in 0..<prices.count {
            var v = 0
            for j in i + 1..<prices.count {
                if prices[i] >= prices[j] {
                    v = prices[j]
                    break
                }
            }
            ans[i] = prices[i] - v
        }
        return ans
    }
}