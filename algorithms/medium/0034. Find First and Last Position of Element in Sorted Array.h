// 34. Find First and Last Position of Element in Sorted Array

// Runtime: 8 ms, faster than 85.57% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 10.3 MB, less than 93.41% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0;
        int r = n;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == target) {
                l = m;
                while (l - 1 >= 0 && nums[l - 1] == target) --l;
                while (m + 1 < n && nums[m + 1] == target) ++m;
                return {l, m};
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return {-1, -1};
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(begin(nums), end(nums), target);
        if (l == end(nums) || *l != target) return {-1, -1};
        auto u = upper_bound(begin(nums), end(nums), target);
        return {(int)(l - begin(nums)), (int)(u - begin(nums)) - 1};
    }
};