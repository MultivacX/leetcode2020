// 27. Remove Element
// https://leetcode.com/problems/remove-element/

// Runtime: 4 ms, faster than 61.60% of C++ online submissions for Remove Element.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Remove Element.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            if (nums[i] != val) ++i;
            else {
                if (j > 0 && nums[j - 1] != val) 
                    swap(nums[i++], nums[j - 1]);
                --j;
            }
        }
        return i;
    }
};