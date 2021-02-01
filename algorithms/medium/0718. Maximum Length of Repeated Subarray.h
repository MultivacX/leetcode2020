// 718. Maximum Length of Repeated Subarray

// Runtime: 216 ms, faster than 32.69% of C++ online submissions for Maximum Length of Repeated Subarray.
// Memory Usage: 105.5 MB, less than 100.00% of C++ online submissions for Maximum Length of Repeated Subarray.

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int m = A.size();
        const int n = B.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};