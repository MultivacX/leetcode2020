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