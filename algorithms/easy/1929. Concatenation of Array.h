// 1929. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/

// Runtime: 20 ms, faster than 50.00% of C++ online submissions for Concatenation of Array.
// Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Concatenation of Array.
    
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums.push_back(nums[i]);
        return nums;
    }
};