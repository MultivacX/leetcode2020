// 1913. Maximum Product Difference Between Two Pairs
// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

// Runtime: 28 ms, faster than 33.33% of C++ online submissions for Maximum Product Difference Between Two Pairs.
// Memory Usage: 20.2 MB, less than 16.67% of C++ online submissions for Maximum Product Difference Between Two Pairs.
    
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        const int n = nums.size();
        sort(begin(nums), end(nums));
        return nums[n - 1] * nums[ n - 2] - nums[1] * nums[0];
    }
};