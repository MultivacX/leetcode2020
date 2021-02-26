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


class Solution {
public:
    bool isMatch(string s, string p) {
        const int M = s.length();
        const int N = p.length();

        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        
        for (int I = 0; I <= M; ++I) {
            int i = I - 1; // [-1, M-1]
            for (int J = 1; J <= N; ++J) {
                int j = J - 1; // [0, N-1]
                
                // '*' Matches empty
                if (p[j] == '*') dp[I][J] = dp[I][J - 1];
                if (dp[I][J] || i < 0) continue;
                
                // '*' Matches 1
                if (p[j] == '*') dp[I][J] = dp[I - 1][J - 1];
                if (dp[I][J]) continue;
                
                // '*' Matches > 1
                if (p[j] == '*') dp[I][J] = dp[I - 1][J];
                if (dp[I][J]) continue;
                
                if (s[i] == p[j] || p[j] == '?') dp[I][J] = dp[I - 1][J - 1];
            }
        }
        return dp[M][N];
    }
};