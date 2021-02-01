// 983. Minimum Cost For Tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/

// Runtime: 4 ms, faster than 92.95% of C++ online submissions for Minimum Cost For Tickets.
// Memory Usage: 9.6 MB, less than 5.03% of C++ online submissions for Minimum Cost For Tickets.

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(1 + days.back() + 29, 0);
        for (int d = 1, j = 0; d < dp.size(); ++d) {
            if (j < days.size() && d == days[j]) { dp[d] = dp[d - 1] + costs[0]; ++j; }
            else dp[d] = dp[d - 1];
            
            if (d >= 7) dp[d] = min(dp[d], dp[d - 7] + costs[1]);
            if (d >= 30) dp[d] = min(dp[d], dp[d - 30] + costs[2]);
        }
        return dp.back();
    }
};