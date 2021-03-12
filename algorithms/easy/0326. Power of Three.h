// 326. Power of Three

// Runtime: 20 ms, faster than 49.97% of C++ online submissions for Power of Three.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Power of Three.

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 || (n & 1) == 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        int64_t x = 1;
        while (x < n) x *= 3;
        return x == n;
    }
};