// 322. Coin Change

// Runtime: 204 ms, faster than 12.16% of C++ online submissions for Coin Change.
// Memory Usage: 13.9 MB, less than 31.37% of C++ online submissions for Coin Change.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int64_t> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin > i) continue;
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};