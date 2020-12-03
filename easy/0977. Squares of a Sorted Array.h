// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

// Runtime: 44 ms, faster than 96.07% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 26.1 MB, less than 79.91% of C++ online submissions for Squares of a Sorted Array.
    
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = n, k = n - 1;
        while (i < j) {
            if (nums[i] * nums[i] <= nums[j - 1] * nums[j - 1]) {
                ans[k--] = nums[j - 1] * nums[j - 1];
                --j;
            } else {
                ans[k--] = nums[i] * nums[i];
                ++i;
            }
        }
        return ans;
    }
};