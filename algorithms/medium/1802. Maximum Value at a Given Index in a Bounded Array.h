// 1802. Maximum Value at a Given Index in a Bounded Array
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Value at a Given Index in a Bounded Array.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Maximum Value at a Given Index in a Bounded Array.
    
class Solution {
    int64_t sum(int64_t maxVal, int64_t n) {
        if (maxVal < n) return n - maxVal + (maxVal + 1) * maxVal / 2;
        return (maxVal + (maxVal - n + 1)) * n / 2;
    }
    
public:
    int maxValue(int n, int index, int maxSum) {
        if (index >= n / 2) index = n - 1 - index;
        // [0,   i]
        // [i, 2*i] [2*i+1, n-1]
        int l = 1, r = maxSum + 1, ans = 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int64_t cur = sum(m, index + 1) + sum(m, n - index) - m;
            if (cur <= maxSum) l = m + 1, ans = max(ans, m);
            else r = m;
        }
        return ans;
    }
};