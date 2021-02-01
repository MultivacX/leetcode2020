// 63. Unique Paths II

// Runtime: 4 ms, faster than 76.99% of C++ online submissions for Unique Paths II.
// Memory Usage: 9.1 MB, less than 96.67% of C++ online submissions for Unique Paths II.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m <= 0) return 0;
        int n = obstacleGrid[0].size();
        if (n <= 0) return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        
        vector<int64_t> fr(m, 1);
        for (int i = 1; i < m; ++i) 
            fr[i] = (fr[i - 1] == 0 || obstacleGrid[i][0] == 1) ? 0 : 1;
        vector<int64_t> dp(n, 1);
        for (int j = 1; j < n; ++j) 
            dp[j] = (dp[j - 1] == 0 || obstacleGrid[0][j] == 1) ? 0 : 1;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;    
                } else if (j == 1) {
                    dp[j] += fr[i];   
                } else {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};