// 44. Wildcard Matching

// Runtime: 600 ms, faster than 5.14% of C++ online submissions for Wildcard Matching.
// Memory Usage: 11.5 MB, less than 46.15% of C++ online submissions for Wildcard Matching.

class Solution {
public:
    bool isMatch(string s, string p) {
        const int M = s.length();
        const int N = p.length();
        int i = 0;
        int j = 0;
        
        // dp[i][j] = isMatch(s[0..i), p[0...j))
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[i][j] = true;
        for (i = 0, j = 1; j <= N && p[j - 1] == '*'; ++j) dp[i][j] = true;
        for (i = 1; i <= M; ++i)  {
            for (j = 1; j <= N; ++j) {
                // single char
                if (dp[i - 1][j - 1] && (p[j - 1] == '*' || p[j - 1] == '?' || p[j - 1] == s[i - 1])) {
                    dp[i][j] = true;
                    continue;
                }
                    
                // any chars
                if (dp[i - 1][j] && p[j - 1] == '*') {
                    dp[i][j] = true;
                    continue;
                }
                
                // empty
                if (dp[i][j - 1] && p[j - 1] == '*') {
                    dp[i][j] = true;
                    continue;
                }
            }
        }
        return dp[M][N];
    }
};