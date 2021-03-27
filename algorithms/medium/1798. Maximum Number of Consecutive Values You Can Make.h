// 1798. Maximum Number of Consecutive Values You Can Make
// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

// Runtime: 164 ms, faster than 32.97% of C++ online submissions for Maximum Number of Consecutive Values You Can Make.
// Memory Usage: 66.7 MB, less than 42.18% of C++ online submissions for Maximum Number of Consecutive Values You Can Make.
    
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(begin(coins), end(coins));
        int next = 1; // 1st num is 0
        for (int i : coins) {
            if (i > next) break;
            next += i;
        }
        return next;
    }
};