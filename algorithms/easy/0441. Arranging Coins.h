// 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arranging Coins.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Arranging Coins.

class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1.0 + 8.0 * n) - 1.0) / 2.0;
    }
};