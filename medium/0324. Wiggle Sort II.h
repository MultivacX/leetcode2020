// 324. Wiggle Sort II
// https://leetcode.com/problems/wiggle-sort-ii/

// Runtime: 52 ms, faster than 67.63% of C++ online submissions for Wiggle Sort II.
// Memory Usage: 17.8 MB, less than 7.19% of C++ online submissions for Wiggle Sort II.

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return;
        sort(begin(nums), end(nums));
        vector<int> tmp(N);
        // [0, (N + 1) / 2 - 1]
        for (int i = (N + 1) / 2 - 1, j = 0; i >= 0 && j < N; --i, j += 2)
            tmp[j] = nums[i];
        // [(N + 1) / 2, N - 1]
        for (int i = N - 1, j = 1; i >= (N + 1) / 2 && j < N; --i, j += 2)
            tmp[j] = nums[i];
        swap(nums, tmp);
    }
};