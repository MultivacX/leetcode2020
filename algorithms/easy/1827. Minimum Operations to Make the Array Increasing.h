// 1827. Minimum Operations to Make the Array Increasing
// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

// Runtime: 16 ms, faster than 50.00% of C++ online submissions for Minimum Operations to Make the Array Increasing.
// Memory Usage: 15.7 MB, less than 75.00% of C++ online submissions for Minimum Operations to Make the Array Increasing.
    
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        for (int i = 1, k = nums[0] + 1; i < n; ++i) {
            if (k <= nums[i]) {
                k = nums[i] + 1;
            } else {
                ans += k - nums[i];
                ++k;
            }
        }
        return ans;
    }
};