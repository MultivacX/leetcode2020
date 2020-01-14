// 724. Find Pivot Index

// Runtime: 36 ms, faster than 16.78% of C++ online submissions for Find Pivot Index.
// Memory Usage: 9.9 MB, less than 66.67% of C++ online submissions for Find Pivot Index.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = accumulate(nums.begin() + 1, nums.end(), 0);
        int i = 0;
        while (i < n) {
            if (left == right) return i;
            left += nums[i];
            i == n - 1 ? 0 : right -= nums[i + 1];
            ++i;
        }
        return -1;
    }
};