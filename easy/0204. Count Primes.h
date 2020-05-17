// 204. Count Primes

// Runtime: 800 ms, faster than 5.02% of C++ online submissions for Count Primes.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Count Primes.

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> nums(n, false);
        for (int i = 2; i * i < n; ++i) {
            for (int j = i; j * i < n; ++j) {
                nums[j * i] = true;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) 
        return ans;
    }
};