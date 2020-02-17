// 91. Decode Ways

// Runtime: 4 ms, faster than 66.97% of C++ online submissions for Decode Ways.
// Memory Usage: 8.7 MB, less than 33.33% of C++ online submissions for Decode Ways.

class Solution {
public:
    int numDecodings(string s) {
        const int n = s.length();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int len = 1; len <= n; ++len) {
            int pre = len - 2;
            int cur = len - 1;
            char c_pre = pre >= 0 ? s[pre] : '0';
            char c_cur = s[cur];
            
            if ((c_pre == '1' || c_pre == '2') && c_cur == '0') {
                dp[len] = dp[len - 2];
            } else if (c_pre == '1' && c_cur <= '9') {
                dp[len] = dp[len - 2] + dp[len - 1];
            } else if (c_pre == '2' && c_cur <= '6') {
                dp[len] = dp[len - 2] + dp[len - 1];
            } else if (c_cur >= '1' && c_cur <= '9') {
                dp[len] = dp[len - 1];
            }
        }
        return dp.back();
    }
};