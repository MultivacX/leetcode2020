// 664. Strange Printer
// https://leetcode.com/problems/strange-printer/

// Runtime: 244 ms, faster than 13.05% of C++ online submissions for Strange Printer.
// Memory Usage: 9 MB, less than 5.48% of C++ online submissions for Strange Printer.

class Solution {
    string reduce(const string& s) {
        string t;
        for (int i = 0; i < s.length(); ++i) 
            if (i == 0 || s[i] != s[i - 1]) 
                t += s[i];
        return t;
    }
    
public:
    int strangePrinter(string s) {
        string t(reduce(s));
        // cout << t << endl;
        const int N = t.length();
        if (N <= 2) return N;
        
        vector<vector<int>> dp(N, vector<int>(N, N));
        for (int len = 2; len <= N; ++len) {
            for (int i = 0, j = len - 1; j < N; ++i, ++j) {
                dp[i][j] = min(dp[i][j], len);
                for (int k = 0; i + k + 1 <= j; ++k) {
                    dp[i][i + k] = min(dp[i][i + k], k + 1);
                    dp[i + k + 1][j] = min(dp[i + k + 1][j], len - k - 1);
                    dp[i][j] = min(dp[i][j], dp[i][i + k] + dp[i + k + 1][j] - (t[i + k] == t[j] ? 1 : 0));
                }
            }
        }
        return dp[0][N - 1];
    }
};