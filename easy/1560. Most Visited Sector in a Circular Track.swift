// 1560. Most Visited Sector in a Circular Track
// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

// Runtime: 20 ms, faster than 25.00% of Swift online submissions for Most Visited Sector in a Circular Track.
// Memory Usage: 13.8 MB, less than 100.00% of Swift online submissions for Most Visited Sector in a Circular Track.

class Solution {
    func mostVisited(_ n: Int, _ rounds: [Int]) -> [Int] {
        var arr = Array(repeating: [0, 0], count: n + 1)
        for i in 1...n { arr[i][0] = i }
        var start = rounds[0]
        for i in 1..<rounds.count {
            var end = rounds[i]
            if start <= end {
                for j in start...end { arr[j][1] += 1 }
            } else {
                for j in start...n { arr[j][1] += 1 }
                for j in 1...end { arr[j][1] += 1 }
            }
            start = end + 1
            if start > n { start = 1 }
        }
        var cnt = 0
        for a in arr { cnt = max(cnt, a[1]) }
        var ans: [Int] = []
        for a in arr { if cnt == a[1] { ans.append(a[0]) } }
        return ans
    }
}