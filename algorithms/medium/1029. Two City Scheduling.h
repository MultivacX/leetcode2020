// 1029. Two City Scheduling
// https://leetcode.com/problems/two-city-scheduling/

// Runtime: 4 ms, faster than 98.76% of C++ online submissions for Two City Scheduling.
// Memory Usage: 8.8 MB, less than 17.08% of C++ online submissions for Two City Scheduling.

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const int N = costs.size();
        const int n = N >> 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 200 * 1000));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (k < 0) { 
                    dp[i][j] = 0; 
                    continue;
                }
                
                int a = costs[k][0];
                int b = costs[k][1];
                if (i == 0) dp[i][j] = b + dp[i][j - 1];
                else if (j == 0) dp[i][j] = a + dp[i - 1][j];
                else dp[i][j] = min(a + dp[i - 1][j], b + dp[i][j - 1]);
                // printf("%d [%d][%d]:%d\n", k, i, j, dp[i][j]);
            }
            // cout << endl;
        }
        return dp[n][n];
    }
};