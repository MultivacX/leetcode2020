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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n <= 1) return 0;
        
        vector<int> buy(n), sell(n), cooldown(n);
        buy[0] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
        }
        
        return max(buy[n - 1], max(sell[n - 1], cooldown[n - 1]));
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n <= 1) return 0;
        
        int buy = -prices[0], sell = 0, cooldown = 0;
        
        for (int i = 1; i < n; ++i) {
            int b = buy, s = sell, c = cooldown;
            buy = max(b, c - prices[i]);
            sell = max(s, b + prices[i]);
            cooldown = max(c, s);
        }
        
        return max(buy, max(sell, cooldown));
    }
};