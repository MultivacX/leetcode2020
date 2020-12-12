// 1608. Special Array With X Elements Greater Than or Equal X
// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.
// Memory Usage: 8.8 MB, less than 33.03% of C++ online submissions for Special Array With X Elements Greater Than or Equal X.
    
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = nums.size() - 1; i >= 0; --i) {
            // left < x <= nums[i]
            int x = nums.size() - i;
            int l = i > 0 ? nums[i - 1] : x - 1;
            if (l < x && x <= nums[i]) return x;
        }
        return -1;
    }
};