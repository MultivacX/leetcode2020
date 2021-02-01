// 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

// Runtime: 48 ms, faster than 45.29% of C++ online submissions for Max Dot Product of Two Subsequences.
// Memory Usage: 13.3 MB, less than 34.35% of C++ online submissions for Max Dot Product of Two Subsequences.

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        const int M = nums1.size();
        const int N = nums2.size();
        vector<vector<int>> dp(M, vector<int>(N, INT_MIN));
        int ans = INT_MIN;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + nums1[i] * nums2[j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};