// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

// Runtime: 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(begin(nums), end(nums), target) - begin(nums);
    }
};