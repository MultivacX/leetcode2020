// 1380. Lucky Numbers in a Matrix
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// Runtime: 200 ms, faster than 23.81% of Swift online submissions for Lucky Numbers in a Matrix.
// Memory Usage: 14.4 MB, less than 19.05% of Swift online submissions for Lucky Numbers in a Matrix.

class Solution {
    func luckyNumbers (_ matrix: [[Int]]) -> [Int] {
        let m = matrix.count
        let n = matrix[0].count
        var mins: [Int: Int] = [:]
        for i in 0..<m {
            mins[i] = matrix[i].min()!
        }
        var ans: [Int] = []
        for j in 0..<n {
            var k = -1
            var v = 0
            for i in 0..<m {
                if v < matrix[i][j] {
                    k = i
                    v = matrix[i][j]
                }
            }
            if mins[k]! == v {
                ans.append(v)
            }
        }
        return ans
    }
}