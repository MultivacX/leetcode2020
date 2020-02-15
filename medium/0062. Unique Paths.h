// 62. Unique Paths

// Runtime: 4 ms, faster than 56.89% of C++ online submissions for Unique Paths.
// Memory Usage: 8.3 MB, less than 84.38% of C++ online submissions for Unique Paths.

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp.back();
    }
};