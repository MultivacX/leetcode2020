// 7. Reverse Integer

// Runtime: 4 ms, faster than 48.43% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Reverse Integer.

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int64_t X = abs((int64_t)x);
        int64_t ans = 0;
        while (X > 0) {
            ans = ans * 10 + X % 10;
            X /= 10;
        }
        if (x < 0) ans *= -1;
        return ans > (int64_t)INT_MAX || ans < (int64_t)INT_MIN ? 0 : ans;
    }
};