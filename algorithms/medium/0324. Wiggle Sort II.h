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


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        const int n = nums.size();
        nth_element(begin(nums), begin(nums) + n / 2, end(nums));
        int m = nums[n / 2];
        
        vector<int> tmp(n, m);
        
        int i = 1, j = n - 1;
        while (j >= n / 2) {
            if (nums[j] > m) {
                tmp[i] = nums[j];
                i += 2;
            }
            --j;
        }
        
        i = (n & 1) ? n - 1 : n - 2, j = 0;
        while (j <= n / 2) {
            if (nums[j] < m) {
                tmp[i] = nums[j];
                i -= 2;
            }
            ++j;
        }
        
        nums = move(tmp);
    }
};