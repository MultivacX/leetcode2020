// 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

// Runtime: 396 ms, faster than 74.63% of C++ online submissions for Maximum Number of Non-Overlapping Subarrays With Sum Equals Target.
// Memory Usage: 85.3 MB, less than 5.19% of C++ online submissions for Maximum Number of Non-Overlapping Subarrays With Sum Equals Target.

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<int> dp(N, 0);
        unordered_map<int, int> presums{{0, -1}};
        for (int i = 0, presum = 0; i < N; ++i) {
            presum += nums[i];
            if (i == 0) {
                dp[i] = presum == target ? 1 : 0;
            } else if (presums.count(presum - target)) {
                int j = presums[presum - target];
                dp[i] = max(dp[i - 1], 1 + (j < 0 ? 0 : dp[j]));
            } else {
                dp[i] = dp[i - 1];
            }
            presums[presum] = i;
        }
        return dp.back();
    }
};