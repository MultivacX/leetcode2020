// 628. Maximum Product of Three Numbers
// https://leetcode.com/problems/maximum-product-of-three-numbers/

// Runtime: 120 ms, faster than 62.02% of C++ online submissions for Maximum Product of Three Numbers.
// Memory Usage: 28.2 MB, less than 94.88% of C++ online submissions for Maximum Product of Three Numbers.

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int N = nums.size();
        return max(
            max(nums[0] * nums[1] * nums[2], nums[N - 3] * nums[N - 2] * nums[N - 1]),
            max(nums[N - 1] * nums[0] * nums[1], nums[N - 2] * nums[N - 1] * nums[0])
        );
    }
};