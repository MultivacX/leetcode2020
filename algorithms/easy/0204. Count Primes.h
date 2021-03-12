// 204. Count Primes

// Runtime: 432 ms, faster than 18.19% of C++ online submissions for Count Primes.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Count Primes.

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> nums(n, false);
        for (int i = 2; i * i < n; ++i) {
            if (nums[i]) continue;
            for (int j = i; j * i < n; ++j) {
                nums[j * i] = true;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) if (!nums[i]) ++ans;
        return ans;
    }
};


class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= n / i; ++j) {
                primes[i * j] = 0;
            }
        }
        return accumulate(begin(primes), end(primes), -primes[n]);
    }
};