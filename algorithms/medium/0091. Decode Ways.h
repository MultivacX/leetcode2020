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


class Solution {
    int check1(const string& s, int i) {
        return '1' <= s[i] && s[i] <= '9' ? 1 : 0;
    }
    
    int check2(const string& s, int i) {
        // if (i == 0) return 0;
        int num = (s[i - 1] - '0') * 10 + s[i] - '0';
        return 10 <= num && num <= 26 ? 1 : 0;
    }
    
public:
    int numDecodings(string s) {
        const int n = s.length();
        int a = check1(s, 0);
        if (a == 0 || n == 1) return a;
        
        vector<int> dp(n);
        dp[0] = a;
        dp[1] = check1(s, 1) + check2(s, 1);
        
        for (int i = 2; i < n; ++i) {
            // [0,i-2][i-1,i]
            int k2 = check2(s, i);
            // [0,i-1][i]
            int k1 = check1(s, i);
            if (k2 + k1 == 0) return 0;
            
            if (k2) dp[i] += dp[i - 2];
            if (k1) dp[i] += dp[i - 1];
        }
        
        return dp[n - 1];
    }
};