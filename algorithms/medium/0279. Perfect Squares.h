// 279. Perfect Squares

// Runtime: 124 ms, faster than 46.36% of C++ online submissions for Perfect Squares.
// Memory Usage: 11.4 MB, less than 61.54% of C++ online submissions for Perfect Squares.

class Solution {
public:
    int numSquares(int n) {
        int v = sqrt(n);
        if (v * v == n) return 1;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            int v = sqrt(i);
            if (v * v == i) {
                dp[i] = 1;    
            } else {
                for (int j = 1; j <= v; ++j) {
                    dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
                }
            }
        }
        return dp[n];
    }
};