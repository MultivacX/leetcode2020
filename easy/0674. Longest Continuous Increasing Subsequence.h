// 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

// Runtime: 16 ms, faster than 85.17% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 11.4 MB, less than 6.12% of C++ online submissions for Longest Continuous Increasing Subsequence.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return N;
        
        int ans = 1;
        for (int i = 1, l = 1; i < N; ++i) {
            if (nums[i] > nums[i - 1]) {
                if (++l > ans) ans = l;
            } else {
                l = 1;
            }
        }
        return ans;
    }
};