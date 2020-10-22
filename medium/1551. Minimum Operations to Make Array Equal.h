// 1551. Minimum Operations to Make Array Equal
// https://leetcode.com/problems/minimum-operations-to-make-array-equal/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Operations to Make Array Equal.
// Memory Usage: 6.1 MB, less than 6.41% of C++ online submissions for Minimum Operations to Make Array Equal.

class Solution {
public:
    int minOperations(int n) {
        // 2*i+1 -> n, i = [0, n-1]
        // sum = n * n
        return n * n / 4;
    }
};