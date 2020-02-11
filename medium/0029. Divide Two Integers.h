// 29. Divide Two Integers

// WRONG
/*class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        
        bool positive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        
        int64_t dd = abs((int64_t)dividend);
        int64_t dr = abs((int64_t)divisor);
        
        return (positive ? 1 : -1) * f(dd, dr);
    }
    
    int f(int64_t dividend, int64_t divisor) {
        if (dividend < divisor) return 0;
        if (dividend == divisor) return 1;
        if (divisor == 1) return dividend;
        
        // dividend > divisor
        int i = 1;
        while (dividend > (divisor << i)) ++i;
        
        // divisor * 2^(i - 1) < dividend <= divisor * 2^i
        int64_t l = divisor << (i - 1);
        int64_t m = l + divisor;
        int64_t r = divisor << i;
        
        cout << l << ", " << m << ", " << r << endl;
        
        if (dividend < m) return 1 << (i - 1);
        if (dividend == m) return (1 << (i - 1)) + 1;
        if (dividend < r) return (1 << i) - 1;
        return 1 << i;
    }
};*/