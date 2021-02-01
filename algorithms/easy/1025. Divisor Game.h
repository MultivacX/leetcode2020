// 1025. Divisor Game

// Runtime: 24 ms, faster than 10.74% of C++ online submissions for Divisor Game.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Divisor Game.

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j < i && !dp[i]; ++j) {
                if (i % j) continue;
                dp[i] = !dp[i - j];
            }
        }
        return dp[N];
    }
};