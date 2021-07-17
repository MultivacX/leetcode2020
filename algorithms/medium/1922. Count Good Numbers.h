// 1922. Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Good Numbers.
// Memory Usage: 5.9 MB, less than 83.94% of C++ online submissions for Count Good Numbers.
    
class Solution {
    static const long long m = 1000000007;
    
    long long cnt(long long k) {
        if (k == 1) return 20;
        
        long long ans = 1;
        if (k & 1) ans = 20, k -= 1;
        long long x = cnt(k / 2);
        return ans * x % m * x % m;
    }
    
public:
    int countGoodNumbers(long long n) {
        if (n == 1) return 5;
        
        // n == odd : 20^(n/2) * 5
        if (n & 1) return 5 * cnt(n / 2) % m;
        
        // n == even : 20^(n/2)
        return cnt(n / 2) % m;
    }
};