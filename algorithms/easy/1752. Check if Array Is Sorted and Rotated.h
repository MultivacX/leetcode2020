// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Array Is Sorted and Rotated.
// Memory Usage: 8.2 MB, less than 25.00% of C++ online submissions for Check if Array Is Sorted and Rotated.
    
class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        
        // nums[s] <= nums[e]
        int s = 0;
        int e = 0;
        while (e + 1 < n && nums[e] <= nums[e + 1]) ++e;
        
        for (int i = e + 1; i < n; ++i) {
            if (nums[s] < nums[i]) return false;
            else if (e + 1 != i && nums[i - 1] > nums[i]) return false;
        }
        return true;
    }
};