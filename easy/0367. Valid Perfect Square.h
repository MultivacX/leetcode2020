// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Valid Perfect Square.

class Solution {
public:
    bool isPerfectSquare(int num) {
        // f(x) = x^2 - num
        // f'(x) = 2*x
        // init : {x0, f(x0)}
        // tangent line: f(x) = (x - x0)*f'(x0) + f(x0)
        // x = x0 * 0.5 + num / x0 * 0.5
        double x = num * 0.5;
        while (abs(x * x - num) > 0.1) {
            x = x * 0.5 + num / x * 0.5;
            // cout << x << " ";
        }
        return (int)x * (int)x == num;
    }
};