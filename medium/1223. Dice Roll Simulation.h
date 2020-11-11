// 1223. Dice Roll Simulation
// https://leetcode.com/problems/dice-roll-simulation/

// Runtime: 36 ms, faster than 72.63% of C++ online submissions for Dice Roll Simulation.
// Memory Usage: 9.4 MB, less than 5.09% of C++ online submissions for Dice Roll Simulation.

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp[L][i] : nums[L - 1] = i
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));
        for (int i = 0; i < 6; ++i) dp[1][i] = 1;
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    dp[L][i] = (dp[L][i] + dp[L - 1][j]) % 1000000007;
                }
                int k = L - rollMax[i];
                for (int j = 0; j < 6 && k > 0; ++j) {
                    if (i != j) { 
                        dp[L][i] = (dp[L][i] - dp[k - 1][j] + 1000000007) % 1000000007;
                    } else if (k == 1 && i == j) {
                        dp[L][i] = (dp[L][i] - 1 + 1000000007) % 1000000007;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; ++i) {
            ans = (ans + dp[n][i]) % 1000000007;
        }
        return ans;
    }
};