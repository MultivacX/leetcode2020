// 1909. Remove One Element to Make the Array Strictly Increasing
// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

// Runtime: 8 ms, faster than 50.00% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
// Memory Usage: 9.8 MB, less than 75.00% of C++ online submissions for Remove One Element to Make the Array Strictly Increasing.
    
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        const int n = nums.size();
        
        int j = 0;
        for (int i = 1, v = nums[i - 1]; i < n && j <= 1; ++i)
            if (v >= nums[i]) 
                v = nums[i - 1], ++j;
            else 
                v = nums[i];
        
        int k = 0;
        for (int i = n - 2, v = nums[i + 1]; i >= 0 && k <= 1; --i) 
            if (nums[i] >= v) 
                v = nums[i + 1], ++k;
            else 
                v = nums[i];
        
        return j <= 1 || k <= 1;
    }
};