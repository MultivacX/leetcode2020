// 1150. Check If a Number Is Majority Element in a Sorted Array
// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

// Runtime: 4 ms, faster than 83.72% of C++ online submissions for Check If a Number Is Majority Element in a Sorted Array.
// Memory Usage: 7.4 MB, less than 99.34% of C++ online submissions for Check If a Number Is Majority Element in a Sorted Array.
    
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        // target - 1 < target <= *l
        auto l = upper_bound(begin(nums), end(nums), target - 1);
        if (l == end(nums) || *l != target) return false;
        
        // target <= *r
        auto r = upper_bound(l, end(nums), target) - 1;
        if (*r != target) return false;
        
        return r - l + 1 > nums.size() / 2;
    }
};