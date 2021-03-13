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


class Solution {
public:
    int mySqrt(int t) {
        // f(x) = x^2 - t
        // f'(x) = 2*x
        
        // y - y0 = k * (x - x0)
        // k = 2 * x0
        // y0 = x0^2 - t
        // target y = 0
        
        // if (t <= 1) return t;
        
        double x = t / 2.0;
        while (abs(x * x - t) > 0.00001) {
            // cout << x << endl;
            double k = 2.0 * x;
            x = x - (x * x - t) / k;
        }
        return x;
    }
};