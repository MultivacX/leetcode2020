// 1800. Maximum Ascending Subarray Sum
// https://leetcode.com/problems/maximum-ascending-subarray-sum/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Ascending Subarray Sum.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Maximum Ascending Subarray Sum.
    
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        for (int i = 1, sum = nums[0]; i < n; ++i) {
            if (nums[i - 1] >= nums[i]) sum = 0;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};