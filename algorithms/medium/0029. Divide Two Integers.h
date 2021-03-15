// 29. Divide Two Integers

// Runtime: 4 ms, faster than 64.70% of C++ online submissions for Divide Two Integers.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Divide Two Integers.

class Solution {
public:
    int divide(int dividend, int divisor) {
        // -INT_MIN = INT_MAX + 1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int64_t dd = abs((int64_t)dividend);
        int64_t dr = abs((int64_t)divisor);
        
        bool positive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        return (positive ? 1 : -1) * f(dd, dr);
    }
    
    int64_t f(int64_t dividend, int64_t divisor) {
        if (dividend < divisor) return 0;
        
        int64_t ans = 0;
        while (dividend >= divisor) {
            int64_t m = divisor;
            int64_t i = 1;
            while (dividend >= m) {
                ans += i;
                
                dividend -= m;
                m <<= 1;
                i <<= 1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int divide(int a, int b) {
        static const int M = INT_MAX;
        static const int HM = INT_MAX >> 1;
        // [-M-1, -M, ..., -1, 0, 1, ..., M]
        // a / b
        
        // 0 / b
        if (a == 0) return 0;
        // a / a
        if (a == b) return 1;
        
        // a / 1
        if (b == 1) return a;
        // a / -1
        if (b == -1) return a == -M-1 ? M : -a;
        
        // |a| < |b|
        // a != b & -M <= a <= M
        if (b == -M-1) return 0;
        if (a != -M-1 && abs(a) < abs(b)) return 0;
        
        // a == -b
        if (a != -M-1 && abs(a) == abs(b)) return -1;
        
        // |a| > |b|
        int ans = 0;
        if (a == -M-1) {
            a = b > 0 ? a + b : a - b;
            ans = 1;
        }
        bool positive = (a > 0 && b > 0) || (a < 0 && b < 0);
        
        a = abs(a), b = abs(b);
        while (a >= b) {
            int k = 0;
            while ((b << k) <= HM && (b << (k + 1)) <= a)
                ++k;
            a -= b << k;
            ans += 1 << k;
        }
        
        return positive ? ans : -ans;
    }
};