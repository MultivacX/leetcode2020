// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

// Runtime: 4 ms, faster than 88.95% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 7 MB, less than 59.64% of C++ online submissions for Regular Expression Matching.

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
                if (i >= 0 && (s[i] == p[j] || '.' == p[j])) {
                    dp[I][J] = dp[I - 1][J - 1];
                } else if ('*' == p[j]) {
                    // Matches 0 of the preceding element.
                    if (J >= 2) dp[I][J] = dp[I][J] || dp[I][J - 2];
                    
                    // Matches 1 of the preceding element.
                    dp[I][J] = dp[I][J] || dp[I][J - 1];
                    
                    // Matches more than 1 of the preceding element.
                    if (i >= 0 && j >= 1 && (s[i] == p[j - 1] || '.' == p[j - 1]))
                        dp[I][J] = dp[I][J] || dp[I - 1][J];
                }
            }
        }
        return dp[M][N];
        
        // 2. split p by X*
        /*auto idx = p.find('*', 0);
        if (idx == string::npos) {
            if (M != N) return false;
            for (int k = 0; k < M; ++k)
                if (s[k] != p[k] && p[k] != '.')
                    return false;
            return true;    
        }

        int i = 0, j = 0;
        while (idx == string::npos) {
            
            idx = p.find('*', idx);
        }
        return true;*/
    }
};