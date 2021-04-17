// 1595. Minimum Cost to Connect Two Groups of Points
// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/

// Runtime: 124 ms, faster than 24.24% of C++ online submissions for Minimum Cost to Connect Two Groups of Points.
// Memory Usage: 9.9 MB, less than 37.88% of C++ online submissions for Minimum Cost to Connect Two Groups of Points.
    
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        const int m = cost.size();
        const int n = cost[0].size();
        const int M = 1e9;
        
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, M));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int s = 0; s < (1 << n); ++s) {
                    dp[i + 1][s | (1 << j)] = min({
                        dp[i + 1][s | (1 << j)],
                        dp[i + 1][s] + cost[i][j],
                        dp[i][s] + cost[i][j]
                    });
                }
            }
        }
        return dp.back().back();
        
        // vector<int> pre(1 << n, M);
        // vector<int> cur(1 << n, M);
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         for (int s = 0; s < (1 << n); ++s) {
        //             if (i + s == 0 && pre[s] == M) 
        //                 pre[s] = 0;
        //             cur[s | (1 << j)] = min({
        //                 cur[s | (1 << j)],
        //                 cur[s] + cost[i][j],
        //                 pre[s] + cost[i][j]
        //             });
        //         }
        //     }
        //     if (i == 0) pre[0] = M;
        //     swap(pre, cur);
        // }
        // return pre.back();
    }
};