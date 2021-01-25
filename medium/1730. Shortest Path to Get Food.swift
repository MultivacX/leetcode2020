// 1730. Shortest Path to Get Food
// https://leetcode.com/problems/shortest-path-to-get-food/

// Runtime: 652 ms, faster than 100.00% of Swift online submissions for Shortest Path to Get Food.
// Memory Usage: 17.2 MB, less than 100.00% of Swift online submissions for Shortest Path to Get Food.

class Solution {
    func getFood(_ grid: [[Character]]) -> Int {
        let m = grid.count
        let n = grid[0].count
        
        var cells: [[Int]] = []
        for i in 0..<m {
            var found = false
            for j in 0..<n {
                if grid[i][j] == "*" {
                    cells.append([i, j])
                    break
                }
            }
            if !cells.isEmpty { break }
        }
        
        var visited: [Int: Int] = [:]
        var path = 0
        while !cells.isEmpty {
            var next: [[Int]] = []
            for cell in cells {
                let i = cell[0]
                let j = cell[1]
                let key = i * n + j
                if visited[key] != nil { continue }
                visited[key] = path
                
                for c in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]] {
                    if c[0] < 0 || c[0] >= m || c[1] < 0 || c[1] >= n { continue }
                    if grid[c[0]][c[1]] == "#" { return path + 1 }
                    if grid[c[0]][c[1]] == "O" && visited[c[0] * n + c[1]] == nil { 
                        next.append(c) 
                    }
                }
            }
            cells = next
            path += 1
        }
        return -1
    }
}