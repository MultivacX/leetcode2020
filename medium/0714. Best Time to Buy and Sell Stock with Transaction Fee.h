// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Runtime: 304 ms, faster than 31.93% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
// Memory Usage: 55.2 MB, less than 60.82% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();
        int buy = -prices[0];
        int sell = 0;
        for (int i = 1; i < N; ++i) {
            int buy_ = buy;
            int sell_ = sell;
            buy = max(buy_, sell_ - prices[i]);
            sell = max(buy_ + prices[i] - fee, sell_);
        }
        return max(buy, sell);
    }
};


// Runtime: 436 ms, faster than 7.38% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
// Memory Usage: 59.8 MB, less than 23.84% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int N = prices.size();
        vector<int> buy(N, 0);
        vector<int> sell(N, 0);
        buy[0] = -prices[0];
        for (int i = 1; i < N; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(buy[i - 1] + prices[i] - fee, sell[i - 1]);
        }
        return max(buy[N - 1], sell[N - 1]);
    }
};