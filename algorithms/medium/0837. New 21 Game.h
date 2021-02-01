// 837. New 21 Game
// https://leetcode.com/problems/new-21-game/

// Runtime: 8 ms, faster than 26.23% of C++ online submissions for New 21 Game.
// Memory Usage: 9.7 MB, less than 35.04% of C++ online submissions for New 21 Game.

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1;
        
        const int L = max(K, W + 1);
        vector<double> dp(L, 0);
        for (int i = 1; i <= W; ++i) dp[i] = 1.0 / W;
            
        // dp[i] = sum(dp[i - w] / W), i > w && w = [1, W]
        double prefix = dp[1];
        for (int i = 2; i < K; ++i) {
            dp[i] += prefix / W;
            prefix = prefix + dp[i] - (i - W > 0 ? dp[i - W] : 0);
        }
        // for (int i = 1; i < K; ++i) printf("%d:%5f ", i, dp[i]); cout << endl;
        
        double ans = 0;
        // K <= i + w <= N
        for (int i = max(1, K - W); i <= K - 1; ++i) {
            int l = K - i;
            int r = min(W, N - i);
            // printf("i:%2d, %f - L:%2d, R:%2d\n", i, dp[i], l, r);
            ans += dp[i] * (r - l + 1) / W;
        }
        for (int i = K; i <= min(N, W); ++i) {
            ans += 1.0 / W;
        }
        return min(ans, 1.0);
    }
};
