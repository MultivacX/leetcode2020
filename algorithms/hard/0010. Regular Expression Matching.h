// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        const int M = s.length();
        const int N = p.length();

        // 1. 
        // dp[i][j] = A: s[i]==p[j] and dp[i-1][j-1]
        //            B:  '.'==p[j] and dp[i-1][j-1]
        //            C:  '*'==p[j]
        //                c1: dp[i][j-2]                      zero p[j-1]
        //
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        auto DP = [&dp](int i, int j){ return dp[i + 1][j + 1]; }
        auto T = [&dp](int i, int j){ dp[i + 1][j + 1] = true; }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((s[i] == p[j] || '.' == p[j]) && DP(i - 1, j - 1)) {
                    T(i, j);
                } else if ('*' == p[j]) {
                    if (s[i] == p[j - 1] || '.' == p[j - 1]) {

                    } else if (DP(i, j - 2)) T(i, j);
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