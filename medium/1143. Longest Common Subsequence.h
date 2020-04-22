// 1143. Longest Common Subsequence

// Runtime: 56 ms, faster than 7.32% of C++ online submissions for Longest Common Subsequence.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Longest Common Subsequence.

// Runtime: O(M*N).
// Memory: O(M*N).

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int M = text1.length();
        const int N = text2.length();
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = max({
                    j > 0 ? dp[i][j - 1] : 0,   
                    i > 0 ? dp[i - 1][j] : 0,
                    (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0) + (text1[i] != text2[j] ? 0 : 1),
                });
                ans = max(ans, dp[i][j]);
            }   
        }
        return ans;
    }
};