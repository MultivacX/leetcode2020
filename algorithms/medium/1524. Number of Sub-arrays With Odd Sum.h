// 1524. Number of Sub-arrays With Odd Sum
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

// Runtime: 328 ms, faster than 66.67% of C++ online submissions for Number of Sub-arrays With Odd Sum.
// Memory Usage: 108.1 MB, less than 100.00% of C++ online submissions for Number of Sub-arrays With Odd Sum.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int M = 1000000007;
        const int N = arr.size();
        int ans = 0;
        int sum = 0;
        int odd_sum_cnt = 0;
        int even_sum_cnt = 0;
        for (int i = 0; i < N; ++i) {
            sum += arr[i];
            if (sum & 1) {
                ++odd_sum_cnt;
                ans = (ans + 1 + even_sum_cnt) % M;
            } else {
                ++even_sum_cnt;
                ans = (ans + odd_sum_cnt) % M;
            }
        }
        return ans;
    }
};