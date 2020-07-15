// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Runtime: 4 ms, faster than 86.34% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
// Memory Usage: 11.5 MB, less than 18.90% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if (N <= 2) return N == 0 ? 0 : max(0, prices.back() - prices.front());
        
        vector<int> buy(N, 0);
        vector<int> sell(N, 0);
        vector<int> cooldown(N, 0);
        buy[0] = -prices[0];
        
        for (int i = 1; i < N; ++i) {
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            cooldown[i] = max(max(buy[i-1], sell[i-1]), cooldown[i-1]);
        }
        
        return max(max(buy[N-1], sell[N-1]), cooldown[N-1]);
    }
};