// 1510. Stone Game IV
// https://leetcode.com/problems/stone-game-iv/

// Runtime: 44 ms, faster than 78.31% of C++ online submissions for Stone Game IV.
// Memory Usage: 21.9 MB, less than 5.18% of C++ online submissions for Stone Game IV.

class Solution {
public:
    bool winnerSquareGame(int n) {
        static vector<int> memo(100001, 0);
        
        if (memo[n] != 0) return memo[n] > 0;
        
        int k = sqrt(n);
        if (n == k * k || n == k * k + 2) {
            memo[n] = 1;
            return true;
        }
        
        // k * k < n
        for (int i = 1; i <= k; ++i) {
            if (!winnerSquareGame(n - i * i)) {
                memo[n] = 1;
                return true;
            }
        }
        
        memo[n] = -1;
        return false;
    }
};