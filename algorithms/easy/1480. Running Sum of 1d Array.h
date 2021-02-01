// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/

// Runtime: 4 ms, faster than 83.95% of C++ online submissions for Running Sum of 1d Array.
// Memory Usage: 8.7 MB, less than 99.71% of C++ online submissions for Running Sum of 1d Array.
    
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        return nums;
    }
};