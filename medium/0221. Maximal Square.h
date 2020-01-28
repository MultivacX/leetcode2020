// 221. Maximal Square

// Runtime: 20 ms, faster than 80.72% of C++ online submissions for Maximal Square.
// Memory Usage: 11.1 MB, less than 62.96% of C++ online submissions for Maximal Square.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if (m == 0) return 0;
        auto n = matrix[0].size();
        if (n == 0) return 0;
        
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                int l = i == 0 ? 0 : dp[i - 1][j];
                int u = j == 0 ? 0 : dp[i][j - 1];
                int e = i == 0 || j == 0 ? 0 : dp[i - 1][j - 1];
                dp[i][j] = 1 + min(l, min(u, e));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};