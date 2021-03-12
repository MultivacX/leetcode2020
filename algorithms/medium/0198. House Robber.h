// 198. House Robber

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) return 0;
        if (N <= 2) return max(nums.front(), nums.back());
        
        int ans = 0;
        vector<int> dp(N, 0);
        for (int i = 0; i < N; ++i) {
            if (i >= 3) {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            } else if (i >= 2) {
                dp[i] = nums[i] + dp[i - 2];
            } else {
                dp[i] = nums[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


class Solution {
    int rob(vector<int>& nums, int i) {
        const int n = nums.size();
        if (i >= n) return 0;
        
        vector<int> dp(n, 0);
        dp[i] = nums[i];
        while (++i < n) 
            dp[i] = max(dp[i - 1], nums[i] + (i >= 2 ? dp[i - 2] : 0));
        return dp[n - 1];
    }
    
public:
    int rob(vector<int>& nums) {
        return max(rob(nums, 0), rob(nums, 1));
    }
};