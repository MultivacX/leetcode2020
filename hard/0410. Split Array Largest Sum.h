// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/

// Runtime: 492 ms, faster than 6.00% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 7.9 MB, less than 14.90% of C++ online submissions for Split Array Largest Sum.

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int N = nums.size();
        vector<int64_t> sums(N, 0);
        for (int64_t i = 0, sum = 0; i < N; ++i) {
            sum += nums[i];
            sums[i] = sum;
        }
        
        vector<vector<int64_t>> dp(N, vector<int64_t>(m + 1, INT_MAX));
        for (int i = 0; i < N; ++i) {
            dp[i][1] = sums[i];

            const int M = min(i + 1, m);
            for (int j = 2; j <= M; ++j) {
                // nums[0, k]_[j-1]parts & [k+1, i]_[1]part
                for (int k = j - 2; k <= i - 1; ++k) {
                    int64_t val = max(dp[k][j - 1], sums[i] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[N - 1][m];
    }
};