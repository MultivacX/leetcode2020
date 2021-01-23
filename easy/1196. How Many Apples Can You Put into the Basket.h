// 1196. How Many Apples Can You Put into the Basket
// https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

// Runtime: 44 ms, faster than 100.00% of Swift online submissions for How Many Apples Can You Put into the Basket.
// Memory Usage: 14.1 MB, less than 100.00% of Swift online submissions for How Many Apples Can You Put into the Basket.

class Solution {
    func maxNumberOfApples(_ arr: [Int]) -> Int {
        let a = arr.sorted()
        var ans = 0
        var sum = 0
        for i in a {
            if sum + i <= 5000 {
                ans += 1
                sum += i
            } else {
                break
            }
        }
        return ans
    }
}