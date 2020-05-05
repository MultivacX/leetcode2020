// 69. Sqrt(x)

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Sqrt(x).

class Solution {
public:
    int mySqrt(int y) {
        // f(x) = x * x - y
        // f'(x) = 2 * x
        // 0 = (x - x0) * f'(x0) + f(x0)
        
        if (y == 0) return 0;
        double x0 = y / 2.0;
        double x = x0 - (x0 * x0 - y) / (2.0 * x0);
        // cout << x0 << ", " << x << endl;
        while (abs(x - x0) >= 1) {
            x0 = x;
            x = x0 - (x0 * x0 - y) / (2.0 * x0);
        }
        return x;
    }
};