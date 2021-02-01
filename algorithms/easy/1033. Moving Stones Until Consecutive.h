// 1033. Moving Stones Until Consecutive
// https://leetcode.com/problems/moving-stones-until-consecutive/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Moving Stones Until Consecutive.
// Memory Usage: 6.5 MB, less than 35.17% of C++ online submissions for Moving Stones Until Consecutive.

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int l = min(a, min(b, c));
        int r = max(a, max(b, c));
        int m = a + b + c - l - r;
        int l2m = m - l - 1;
        int r2m = r - m - 1;
        return {(l2m == 1 || r2m == 1) ? 1 : (l2m > 0) + (r2m > 0), l2m + r2m};
    }
};