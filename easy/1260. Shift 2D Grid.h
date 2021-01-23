// 1260. Shift 2D Grid
// https://leetcode.com/problems/shift-2d-grid/

// Runtime: 192 ms, faster than 100.00% of Swift online submissions for Shift 2D Grid.
// Memory Usage: 14.7 MB, less than 30.77% of Swift online submissions for Shift 2D Grid.

class Solution {
    func shiftGrid(_ grid: [[Int]], _ k: Int) -> [[Int]] {
        if k == 0 {
            return grid
        }
        
        let m = grid.count
        let n = grid[0].count
        var ans = grid
        for i in 0..<m {
            for j in 0..<n {
                let i1 = (i + (j + k) / n) % m
                let j1 = (j + k) % n
                ans[i1][j1] = grid[i][j]
            }
        }
        return ans
    }
}