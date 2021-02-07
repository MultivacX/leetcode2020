// 1749. Maximum Absolute Sum of Any Subarray
// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

// Runtime: 64 ms, faster than 87.50% of C++ online submissions for Maximum Absolute Sum of Any Subarray.
// Memory Usage: 41.3 MB, less than 100.00% of C++ online submissions for Maximum Absolute Sum of Any Subarray.
    
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0;
        int maxSum = 0;
        int ans = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);
            sum += nums[i];
            ans = max(ans, abs(sum - minSum));
            ans = max(ans, abs(sum - maxSum));
        }
        return ans;
    }
};