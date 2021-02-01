// 999. Available Captures for Rook
// https://leetcode.com/problems/available-captures-for-rook/

// Runtime: 8 ms, faster than 81.82% of Swift online submissions for Available Captures for Rook.
// Memory Usage: 13.9 MB, less than 100.00% of Swift online submissions for Available Captures for Rook.

class Solution {
    func numRookCaptures(_ board: [[Character]]) -> Int {
        var ri = -1
        var rj = -1
        for i in 0..<8 {
            for j in 0..<8 {
                if board[i][j] == "R" {
                    ri = i
                    rj = j
                    break
                }
            }   
            if ri > -1 { break }
        }
        if ri == -1 { return 0 }
        
        var ans = 0
        for j in stride(from: rj - 1, to: -1, by: -1) {
            if board[ri][j] == "." { continue }
            if board[ri][j] == "p" { ans += 1 }
            break
        }
        for j in stride(from: rj + 1, to: 8, by: 1) {
            if board[ri][j] == "." { continue }
            if board[ri][j] == "p" { ans += 1 }
            break
        }
        for i in stride(from: ri - 1, to: -1, by: -1) {
            if board[i][rj] == "." { continue }
            if board[i][rj] == "p" { ans += 1 }
            break
        }
        for i in stride(from: ri + 1, to: 8, by: 1) {
            if board[i][rj] == "." { continue }
            if board[i][rj] == "p" { ans += 1 }
            break
        }
        return ans
    }
}