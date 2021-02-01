// 64. Minimum Path Sum

// Runtime: 8 ms, faster than 88.30% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 10.5 MB, less than 94.74% of C++ online submissions for Minimum Path Sum.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0) return 0;
        const int n = grid[0].size();
        if (n == 0) return 0;
        
        vector<int64_t> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = grid[0][j] + dp[j - 1];
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
            }
        }
        return dp.back();
    }
};