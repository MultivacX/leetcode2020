// 72. Edit Distance

// Runtime: 24 ms, faster than 15.84% of C++ online submissions for Edit Distance.
// Memory Usage: 9 MB, less than 87.50% of C++ online submissions for Edit Distance.

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int M = word1.length();
        const int N = word2.length();
        vector<vector<int>> dp(1 + M, vector<int>(1 + N, M * N));
        dp[0][0] = 0;
        for (int i = 1; i <= M; ++i) dp[i][0] = i;
        for (int j = 1; j <= N; ++j) dp[0][j] = j;
        
        // dp[i][j] -> insert -> dp[i][j + 1]
        // dp[i][j] -> replace or word1[i] == word2[j] -> dp[i + 1][j + 1]
        // dp[i][j] -> delete -> dp[i + 1][j]
        
        // dp[i][j - 1]     ->                 insert                  -> dp[i][j]
        // dp[i - 1][j - 1] -> replace or word1[i - 1] == word2[j - 1] -> dp[i][j]
        // dp[i - 1][j]     ->                 delete                  -> dp[i][j]
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
                dp[i][j] = min(dp[i][j], (word1[i - 1] == word2[j - 1] ? 0 : 1) + dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
            }
        }
        
        return dp[M][N];
    }
};