// 123. Best Time to Buy and Sell Stock III

// Runtime: 4 ms, faster than 98.51% of C++ online submissions for Best Time to Buy and Sell Stock III.
// Memory Usage: 9.8 MB, less than 35.71% of C++ online submissions for Best Time to Buy and Sell Stock III.

class Solution {
public:
	int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        auto L(f(prices));
        auto R(h(prices));
        int ans = L.back();
        for (int i = 0; i < n - 1; ++i) {
            int profit = L[i] + R[i + 1];
            ans = max(ans, profit);
        }
        return ans;
    }
    
    vector<int> f(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int low = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - low;
            dp[i] = max(dp[i - 1], profit);
            low = min(low, prices[i]);
        }
        return dp;
    }
    
    vector<int> h(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        int up = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            int profit = up - prices[i];
            dp[i] = max(dp[i + 1], profit);
            up = max(up, prices[i]);
        }
        return dp;
    }

	// Time Limit Exceeded
    /*int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = maxProfit(prices, 0, i, n);
            int r = maxProfit(prices, i, n, n);
            ans = max(ans, l + r);
        }
        return ans;
    }
    
    int maxProfit(vector<int>& prices, int l, int r, int n) {
        if (l >= r || l >= n) return 0;
        
        int ans = 0;
        int left = prices[l];
        for (int i = l + 1; i < r && i < n; ++i) {
            int profit = prices[i] - left;
            ans = max(ans, profit);
            left = min(left, prices[i]);
        }
        return ans;
    }*/
};