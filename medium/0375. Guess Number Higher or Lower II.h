// 375. Guess Number Higher or Lower II
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

// Runtime: 300 ms, faster than 21.76% of C++ online submissions for Guess Number Higher or Lower II.
// Memory Usage: 8.6 MB, less than 14.35% of C++ online submissions for Guess Number Higher or Lower II.
    
class Solution {
    int guess(int l, int r, vector<vector<int>>& memo) {
        if (l >= r) return 0;
        
        if (memo[l][r] > 0) return memo[l][r];
        
        int v = INT_MAX;
        for (int i = l; i <= r; ++i) {
            int x = i + max(guess(l, i - 1, memo), guess(i + 1, r, memo));
            v = min(v, x);
        }
        memo[l][r] = v;
        return v;
    }
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        return guess(1, n, memo);
    }
};