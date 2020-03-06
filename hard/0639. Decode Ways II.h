// 639. Decode Ways II

// Runtime: 56 ms, faster than 77.20% of C++ online submissions for Decode Ways II.
// Memory Usage: 18.2 MB, less than 25.00% of C++ online submissions for Decode Ways II.

class Solution {
public:
    int numDecodings(string s) {
        const int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;
        for (int len = 2; len <= n; ++len) {
            // char c0 = len >= 3 ? s[len - 3] : '#';
            char c1 = len >= 2 ? s[len - 2] : '#';
            char c2 = s[len - 1];
            
            // * or x, x = [1, 9]
            int64_t cnt = (c2 == '*' ? 9 : (c2 == '0' ? 0 : 1)) * (int64_t)dp[len - 1] % 1000000007;
            dp[len] = (int64_t)(dp[len] + cnt) % 1000000007;
            
            if (c1 == '1') {
                cnt = 0;
                // 11 ~ 19
                if (c2 == '*') cnt = 9 * (int64_t)dp[len - 2] % 1000000007;
                // 1x, x = [0, 9]
                else cnt = dp[len - 2] % 1000000007;
                dp[len] = (int64_t)(dp[len] + cnt) % 1000000007;
            } else if (c1 == '2') {
                cnt = 0;
                // 21 ~ 26
                if (c2 == '*') cnt = 6 * (int64_t)dp[len - 2] % 1000000007;
                // 2x, x = [0, 6]
                else if (c2 < '7') cnt = dp[len - 2] % 1000000007;
                dp[len] = (int64_t)(dp[len] + cnt) % 1000000007;
            } else if (c1 == '*') {
                cnt = 0;
                // 11 ~ 19 and 21 ~ 26
                if (c2 == '*') cnt = 15 * (int64_t)dp[len - 2] % 1000000007;
                // 1x and 2x, x = [0, 6]
                else if (c2 < '7')  cnt = 2 * (int64_t)dp[len - 2] % 1000000007;
                // 1x, x = [7, 9]
                else cnt = dp[len - 2] % 1000000007;
                dp[len] = (int64_t)(dp[len] + cnt) % 1000000007;
            }
        }
        return dp.back();
    }
};