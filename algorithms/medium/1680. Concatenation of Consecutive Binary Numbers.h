// 1680. Concatenation of Consecutive Binary Numbers
// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// Runtime: 60 ms, faster than 74.88% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
// Memory Usage: 6.3 MB, less than 66.84% of C++ online submissions for Concatenation of Consecutive Binary Numbers.
    
class Solution {
public:
    int concatenatedBinary(int n) {
        static const uint64_t m = 1000000007;
        uint64_t ans = 0;
        for (uint64_t i = n, b = 0, v = 1; i >= 1; --i) {
            // cout << i << ": " << bitset<16>(i) << "  " << bitset<16>(1 << b) << endl;
            // cout << bitset<16>(i * (1 << b)) << endl;
            v = (v * (1 << b) % m) % m;
            ans = (ans + i * v % m) % m;
            b = 32 - __builtin_clz(i);
        }
        return ans;
    }
};