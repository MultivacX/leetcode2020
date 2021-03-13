// 50. Pow(x, n)

// Runtime: 4 ms, faster than 59.29% of C++ online submissions for Pow(x, n).
// Memory Usage: 8.4 MB, less than 64.29% of C++ online submissions for Pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        
        int64_t _n = abs(n / 2);
        double half = myPow(x, _n);
        return n < 0 ? 1.0 / (half * half * (n % 2 == 0 ? 1 : x)) : (half * half * (n % 2 == 0 ? 1 : x));
    }
};


class Solution {
    unordered_map<int, double> dp;
    
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1.0 / x;
        if (x == 0) return 0;
        if (x == 1) return x;
        if (x == -1) return (n & 1) ? -1 : 1;
        if (dp.count(n)) return dp[n];
        
        return dp[n] = myPow(x, n / 2) * myPow(x, n - n / 2);
    }
};