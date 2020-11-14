// 1416. Restore The Array
// https://leetcode.com/problems/restore-the-array/

// Runtime: 40 ms, faster than 97.35% of C++ online submissions for Restore The Array.
// Memory Usage: 14.6 MB, less than 53.98% of C++ online submissions for Restore The Array.

class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int N = s.length();
        vector<int64_t> dp(N + 1, 0);
        dp[N] = 1;
        for (int i = N - 1; i >= 0; --i) {
            int64_t n = s[i] - '0';
            if (n == 0 || n > k) continue;

            dp[i] = dp[i + 1];
            for (int j = i + 2; j <= N; ++j) {
                n = n * 10 + s[j - 1] - '0';
                if (n <= k) dp[i] += dp[j];
                else break;
            }
            dp[i] %= 1000000007;
        }
        return dp[0] % 1000000007;
    }
};