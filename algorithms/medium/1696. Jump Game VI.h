// 1696. Jump Game VI
// https://leetcode.com/problems/jump-game-vi/

// Runtime: 736 ms, faster than 12.67% of C++ online submissions for Jump Game VI.
// Memory Usage: 119.9 MB, less than 5.97% of C++ online submissions for Jump Game VI.
    
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> dp(N, INT_MIN);
        dp[0] = nums[0];
        map<int, int> m{{nums[0], 1}};
        for (int i = 1; i < N; ++i) {
            if (i > k && --m[dp[i - k - 1]] == 0) 
                m.erase(dp[i - k - 1]);
            int maxv = m.crbegin()->first;
            dp[i] = maxv + nums[i];
            ++m[dp[i]];
        }
        return dp[N - 1];
    }
};