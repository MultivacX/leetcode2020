// 516. Longest Palindromic Subsequence

// Runtime: 208 ms, faster than 11.14% of C++ online submissions for Longest Palindromic Subsequence.
// Memory Usage: 67.3 MB, less than 100.00% of C++ online submissions for Longest Palindromic Subsequence.

// Time Complexity: O(N * N).
// Space Complexity: O(N).

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.length();
        string t(rbegin(s), rend(s));
        return lcs(s, t);
    }
    
    int lcs(const string& word1, const string& word2) {
        const int M = word1.length();
        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        // cout << "# "; for (int j = 1; j <= N; ++j) cout << word2[j - 1] << " "; cout << endl;
        for (int i = 1; i <= M; ++i) {
            // cout << word1[i - 1] << " ";
            for (int j = 1; j <= M; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[M][M];
    }
};