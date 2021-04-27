// 1799. Maximize Score After N Operations
// https://leetcode.com/problems/maximize-score-after-n-operations/

// Runtime: 192 ms, faster than 55.53% of C++ online submissions for Maximize Score After N Operations.
// Memory Usage: 17.6 MB, less than 30.53% of C++ online submissions for Maximize Score After N Operations.
    
class Solution { 
public:
    int maxScore(vector<int>& nums) {
        const int n = nums.size() >> 1;
        vector<vector<int>> dp(n + 1, vector<int>(1 << (n * 2)));
        for (int mask = 0; mask < 1 << (n * 2); ++mask) {
            int k = __builtin_popcount(mask);
            if (k & 1) continue;
            
            int opt = (k >> 1) + 1;
            for (int i = 0; i + 1 < n * 2; ++i) {
                if (mask & (1 << i)) continue;
                
                for (int j = i + 1; j < n * 2; ++j) {
                    if (mask & (1 << j)) continue;
                    
                    int nm = mask | (1 << i) | (1 << j);
                    int score = opt * gcd(nums[i], nums[j]);
                    dp[opt][nm] = max(dp[opt][nm], score + dp[opt - 1][mask]);
                }    
            }
        }
        return dp.back().back();
    }
};