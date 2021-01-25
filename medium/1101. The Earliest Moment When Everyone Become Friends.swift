// 1101. The Earliest Moment When Everyone Become Friends
// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

// Runtime: 156 ms, faster than 60.00% of Swift online submissions for The Earliest Moment When Everyone Become Friends.
// Memory Usage: 14.4 MB, less than 26.67% of Swift online submissions for The Earliest Moment When Everyone Become Friends.

class Solution {
    func find(_ parents: inout [[Int]], _ i: Int) -> Int {
        var pi = parents[i][0]
        if pi != i {
            pi = find(&parents, pi)
        }
        parents[i][0] = pi
        return pi
    }
    
    func union(_ parents: inout [[Int]], _ i: Int, _ j: Int) -> Int {
        let pi = find(&parents, i)
        let pj = find(&parents, j)
        if pi == pj { return parents[pi][1] }
        
        if parents[pi][1] < parents[pj][1] { 
            parents[pi][0] = pj
            parents[pj][1] += parents[pi][1]
            return parents[pj][1]
        } else {
            parents[pj][0] = pi
            parents[pi][1] += parents[pj][1]
            return parents[pi][1]
        }
    }
    
    func earliestAcq(_ logs: [[Int]], _ N: Int) -> Int {
        var parents = Array(repeating: [0, 1], count: N + 1)
        for i in 1...N { parents[i][0] = i }
        
        for log in logs.sorted{ $0[0] < $1[0] } {
            if union(&parents, log[1], log[2]) == N { 
                return log[0] 
            }
        } 
        return -1
    }
}