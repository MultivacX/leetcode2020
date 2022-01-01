// 2119. A Number After a Double Reversal
// https://leetcode.com/problems/a-number-after-a-double-reversal/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for A Number After a Double Reversal.
// Memory Usage: 5.9 MB, less than 21.59% of C++ online submissions for A Number After a Double Reversal.

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        return num < 10 || num != num / 10 * 10;
    }
};