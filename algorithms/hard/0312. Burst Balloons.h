// 312. Burst Balloons
// https://leetcode.com/problems/burst-balloons/

// Runtime: 40 ms, faster than 42.97% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.2 MB, less than 17.68% of C++ online submissions for Burst Balloons.

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int N = nums.size();
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // nums[i-1] dp[i][k-1] nums[k] dp[k+1][j] nums[j+1]
        // dp[i][j] = max(dp[i][k-1] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j+1])
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        for (int L = 1; L <= N; ++L) {
            for (int i = 1; i + L - 1 <= N; ++i) {
                int j = i + L - 1;
                // cout << i << ", " << j << ": ";
                for (int k = i; k <= j; ++k) {
                    // printf("%d ", nums[k]);
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j]);
                }
                // cout << endl;
            }
        }
        return dp[1][N];
    }
};