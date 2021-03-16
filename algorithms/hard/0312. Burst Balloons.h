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


class Solution {
    int maxCoins(const vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (memo[i][j] != 0) return memo[i][j];
        
        int ans = 0;
        // [i,k-1] k [k+1,j]
        for (int k = i; k <= j; ++k) {
            int cur = maxCoins(nums, i, k - 1, memo) + 
                      maxCoins(nums, k + 1, j, memo) +
                      nums[i - 1] * nums[k] * nums[j + 1];
            if (cur > ans) ans = cur;
        }
        memo[i][j] = ans;
        return ans;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        nums.insert(begin(nums), 1);
        nums.push_back(1);
        vector<vector<int>> memo(n + 2, vector<int>(n + 2));
        return maxCoins(nums, 1, n, memo);
    }
};