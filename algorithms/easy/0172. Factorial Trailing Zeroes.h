// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Factorial Trailing Zeroes.
// Memory Usage: 6.1 MB, less than 34.84% of C++ online submissions for Factorial Trailing Zeroes.

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5) return 0;
        return n / 5 + trailingZeroes(n / 5);
    }
};


class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i *= 5)
            ans += n / i;
        return ans;
    }
};