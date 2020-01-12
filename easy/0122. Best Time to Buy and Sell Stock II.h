// 122. Best Time to Buy and Sell Stock II

// Runtime: 4 ms, faster than 98.10% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 9.5 MB, less than 85.71% of C++ online submissions for Best Time to Buy and Sell Stock II.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            int profit = prices[i + 1] - prices[i];
            if (profit > 0) ans += profit;
        }
        return ans;
    }
};