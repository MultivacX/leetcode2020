// 1652. Defuse the Bomb
// https://leetcode.com/problems/defuse-the-bomb/

// Runtime: 8 ms, faster than 96.67% of Swift online submissions for Defuse the Bomb.
// Memory Usage: 14.5 MB, less than 16.67% of Swift online submissions for Defuse the Bomb.

class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        let n = code.count
        var arr = Array(repeating: 0, count: n)
        if k == 0 { return arr }
        var sum = 0
        for i in 0..<n {
            if sum == 0 {
                for j in 1...abs(k) {
                    sum += code[(n + i + (k < 0 ? -j : j)) % n]
                }
            } else if k > 0 {
                sum -= code[i]
                sum += code[(n + i + k) % n]
            } else {
                sum += code[i - 1]
                sum -= code[(n + i + k - 1) % n]
            }
            arr[i] = sum
        }
        return arr
    }
}