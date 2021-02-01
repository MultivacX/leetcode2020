// 1688. Count of Matches in Tournament
// https://leetcode.com/problems/count-of-matches-in-tournament/

// Runtime: 0 ms, faster than 100.00% of Swift online submissions for Count of Matches in Tournament.
// Memory Usage: 13.9 MB, less than 26.50% of Swift online submissions for Count of Matches in Tournament.

class Solution {
    func numberOfMatches(_ n: Int) -> Int {
        if n <= 1 { return 0 }
        var ans  = n / 2
        ans += numberOfMatches(ans + n % 2)
        return ans
    }
}