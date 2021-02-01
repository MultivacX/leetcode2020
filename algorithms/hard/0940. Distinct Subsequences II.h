// 940. Distinct Subsequences II
// https://leetcode.com/problems/distinct-subsequences-ii/

// Runtime: 8 ms, faster than 67.12% of C++ online submissions for Distinct Subsequences II.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Distinct Subsequences II.

class Solution {
public:
    int distinctSubseqII(string S) {
        static const int MOD = 1000000007;
        const int N = S.length();
        vector<int> last(26, -1);
        last[S[0] - 'a'] = 0;
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        for (int i = 1; i < N; ++i) {
            int j = S[i] - 'a';
            int64_t recounted = last[j] < 0 ? 0 : (dp[last[j]] + 1);
            
            int len = i + 1;
            int64_t cnt = dp[len - 1] * 2 + 1 - recounted;
            cnt = (cnt + MOD) % MOD;
            
            dp[len] = cnt;
            last[j] = i;
        }
        return dp[N];
    }
};