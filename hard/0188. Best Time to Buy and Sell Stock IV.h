// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// Runtime: 108 ms, faster than 20.47% of C++ online submissions for Best Time to Buy and Sell Stock IV.
// Memory Usage: 22.3 MB, less than 6.47% of C++ online submissions for Best Time to Buy and Sell Stock IV.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0) return 0;
        
        const int DAYS = prices.size();
        // if (DAYS <= 1) return 0;
        if (2 * k >= DAYS) {
            int ans = 0;
            for (int i = 1; i < DAYS; ++i) 
                if (prices[i - 1] < prices[i]) 
                    ans += prices[i] - prices[i - 1];
            return ans;    
        }
        
        // [day][used_transactions][hold_1_stock]
        vector<vector<vector<int64_t>>> dp(DAYS, vector<vector<int64_t>>(k + 1, {INT_MIN, INT_MIN}));
        
        dp[0][0][0] = 0;          // at day-0, do nothing
        dp[0][1][1] = -prices[0]; // at day-0, use 1 transaction to buy current stock
        
        for (int i = 1; i < DAYS; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                if (j > 0) dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        
        int64_t ans = 0;
        for (int j = 0; j <= k; ++j)
            ans = max(ans, dp[DAYS - 1][j][0]);
        return ans;
    }
};