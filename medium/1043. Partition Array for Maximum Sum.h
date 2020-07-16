// 1043. Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/

// Runtime: 60 ms, faster than 18.30% of C++ online submissions for Partition Array for Maximum Sum.
// Memory Usage: 8.7 MB, less than 57.56% of C++ online submissions for Partition Array for Maximum Sum.

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const int N = A.size();
        vector<int> dp(N, 0);
        dp[0] = A[0];
        for (int i = 1; i < N; ++i) {
            int val = A[i];
            dp[i] = val + dp[i - 1];
            for (int j = i - 1; j >= max(0, i - K + 1); --j) {
                val = max(val, A[j]);
                dp[i] = max(dp[i], val * (i - j + 1) + (j > 0 ? dp[j - 1] : 0));
            }
        }
        return dp[N - 1];
    }
};