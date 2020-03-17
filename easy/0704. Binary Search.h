// 704. Binary Search

// Runtime: 52 ms, faster than 67.94% of C++ online submissions for Binary Search.
// Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Binary Search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        while (i < j) {
            int k = i + (j - i) / 2;
            if (nums[k] == target) return k;
            if (nums[k] > target) j = k;
            else i = k + 1;
        }
        return -1;
    }
};