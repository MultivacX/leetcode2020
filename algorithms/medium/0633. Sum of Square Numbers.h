// 633. Sum of Square Numbers

// Runtime: 4 ms, faster than 67.62% of C++ online submissions for Sum of Square Numbers.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Sum of Square Numbers.

// Time Complexity: O(sqrt(c)*sqrt_time).
// Space Complexity: O(1).

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a * a <= c - a * a; ++a) {
            int b = sqrt(c - a * a);
            if (a * a + b * b == c) return true;
        }
        return false;
    }
};