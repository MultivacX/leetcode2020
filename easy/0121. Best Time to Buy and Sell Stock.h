// 121. Best Time to Buy and Sell Stock

// Runtime: 8 ms, faster than 68.10% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.6 MB, less than 74.31% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int ans = 0;
        int l = prices[0];
        for (int i = 1; i < n; ++i) {
            int profit = prices[i] - l;
            ans = max(ans, profit);
            l = min(l, prices[i]);
        }
        return ans;
    }
};