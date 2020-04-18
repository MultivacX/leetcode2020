// 931. Minimum Falling Path Sum

// Runtime: 24 ms, faster than 7.37% of C++ online submissions for Minimum Falling Path Sum.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Minimum Falling Path Sum.

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        for (int j = 0; j < N; ++j) dp[0][j] = A[0][j];
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = A[i][j] + min({
                    j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX, 
                    dp[i - 1][j], 
                    j + 1 < N ? dp[i - 1][j + 1] : INT_MAX});
            }
        }
        return *min_element(begin(dp[N - 1]), end(dp[N - 1]));
    }
};