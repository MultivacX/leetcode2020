// 479. Largest Palindrome Product
// https://leetcode.com/problems/largest-palindrome-product/

// Runtime: 212 ms, faster than 79.75% of C++ online submissions for Largest Palindrome Product.
// Memory Usage: 6.9 MB, less than 12.66% of C++ online submissions for Largest Palindrome Product.

class Solution {
    uint64_t get_p(uint64_t half) {
        string l(to_string(half));
        string r(l);
        reverse(begin(r), end(r));
        return stoll(l + r);
    }
    
public:
    int largestPalindrome(int n) {
        uint64_t l = pow(10, n - 1);
        uint64_t r = pow(10, n) - 1;
        // cout << l << ", " << r << endl;
        
        for (uint64_t half = r; half >= l; --half) {
            uint64_t p = get_p(half);
            for (uint64_t y = r; y * y >= p; --y) {
                uint64_t x = p / y;
                if (x >= l && x * y == p) return p % 1337;
            }
        }
        return r % 1337;
    }
};