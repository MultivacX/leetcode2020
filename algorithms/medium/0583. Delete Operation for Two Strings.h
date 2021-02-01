// 583. Delete Operation for Two Strings

// Runtime: 20 ms, faster than 72.02% of C++ online submissions for Delete Operation for Two Strings.
// Memory Usage: 11.9 MB, less than 55.56% of C++ online submissions for Delete Operation for Two Strings.

// Time Complexity: O(M * N).
// Space Complexity: O(M * N).

class Solution {
public:
    int minDistance(string word1, string word2) {
        // lcs
        const int M = word1.length();
        const int N = word2.length();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        // cout << "# "; for (int j = 1; j <= N; ++j) cout << word2[j - 1] << " "; cout << endl;
        for (int i = 1; i <= M; ++i) {
            // cout << word1[i - 1] << " ";
            for (int j = 1; j <= N; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = max(1 + dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
                else dp[i][j] = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return M + N - dp[M][N] * 2;
    }
};