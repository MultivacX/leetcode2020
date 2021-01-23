// 1582. Special Positions in a Binary Matrix
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

// Runtime: 172 ms, faster than 28.57% of Swift online submissions for Special Positions in a Binary Matrix.
// Memory Usage: 14 MB, less than 71.43% of Swift online submissions for Special Positions in a Binary Matrix.

class Solution {
    func numSpecial(_ mat: [[Int]]) -> Int {
        var rows: [Int: Int] = [:]
        var cols: [Int: Int] = [:]
        for i in 0..<mat.count {
            for j in 0..<mat[i].count {
                if mat[i][j] == 0 { continue }
                if let v = rows[i] { rows[i] = v + 1 }
                else { rows[i] = 1 }
                if let v = cols[j] { cols[j] = v + 1 }
                else { cols[j] = 1 }
            }
        }
        
        var cnt = 0
        for i in 0..<mat.count {
            for j in 0..<mat[i].count {
                if mat[i][j] == 0 { continue }
                if rows[i]! + cols[j]! == 2 { cnt += 1 }
            }
        }
        return cnt
    }
}