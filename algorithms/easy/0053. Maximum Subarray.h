// 53. Maximum Subarray

// Runtime: 8 ms, faster than 72.05% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.2 MB, less than 91.18% of C++ online submissions for Maximum Subarray.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum < nums[i]) {
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};