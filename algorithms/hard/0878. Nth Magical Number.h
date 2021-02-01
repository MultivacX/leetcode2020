// 878. Nth Magical Number
// https://leetcode.com/problems/nth-magical-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Nth Magical Number.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Nth Magical Number.

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        if (A > B) swap(A, B);
        uint64_t lcm_ = lcm(A, B);
        uint64_t lo = 0;
        uint64_t hi = (uint64_t)N * A;
        while (lo < hi) {
            uint64_t mid = lo + (hi - lo) / 2;
            uint64_t cnt = mid / A + mid / B - mid / lcm_;
            if (cnt < N) lo = mid + 1;
            else hi = mid;
        }
        return lo % 1000000007;
    }
};