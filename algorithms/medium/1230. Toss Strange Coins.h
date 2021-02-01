// 1230. Toss Strange Coins
// https://leetcode.com/problems/toss-strange-coins/

// Runtime: 212 ms, faster than 6.32% of C++ online submissions for Toss Strange Coins.
// Memory Usage: 55 MB, less than 67.37% of C++ online submissions for Toss Strange Coins.
    
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        const int N = prob.size();
        // dp[i][j] : toss i coins and get j heads
        vector<vector<double>> dp(N + 1, vector<double>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= min(i, target); ++j) {
                if (j > 0) dp[i][j] += dp[i - 1][j - 1] * prob[i - 1];
                dp[i][j] += dp[i - 1][j] * (1 - prob[i - 1]);
            }
        }
        return dp[N][target];
    }
};