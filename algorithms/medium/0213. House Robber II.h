// 213. House Robber II

// Runtime: 4 ms, faster than 59.94% of C++ online submissions for House Robber II.
// Memory Usage: 8.6 MB, less than 88.57% of C++ online submissions for House Robber II.

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n <= 3) return max(nums[n >> 1], max(nums.front(), nums.back()));
        
        int ans = 0;
        int _max = 0;
        vector<int> dp(n, 0);
        // dp[i] = nums[i] + max(dp[0, ..., i - 2])
        
        for (int i = 0; i < n - 1; ++i) {
            if (i - 2 >= 0) _max = max(_max, dp[i - 2]);
            dp[i] = nums[i] + _max;
            ans = max(ans, dp[i]);
        }
        
        _max = 0;
        fill(dp.begin(), dp.end(), 0);
        
        for (int i = 1; i < n; ++i) {
            if (i - 2 >= 0) _max = max(_max, dp[i - 2]);
            dp[i] = nums[i] + _max;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) return max(nums.front(), nums.back());
        
        int ans = 0;
        
        vector<int> dp(N, 0);
        for (int i = 0; i < N - 1; ++i) {
            if (i == 0) dp[i] = nums[i];
            else if (i == 1) dp[i] = max(nums[i], dp[i - 1]);
            else dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            ans = max(ans, dp[i]);
        }
        
        fill(dp.begin(), dp.end(), 0);
        for (int i = 1; i < N; ++i) {
            if (i == 1) dp[i] = nums[i];
            else if (i == 2) dp[i] = max(nums[i], dp[i - 1]);
            else dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};