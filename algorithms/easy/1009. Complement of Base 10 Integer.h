// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complement of Base 10 Integer.
// Memory Usage: 6.2 MB, less than 28.22% of C++ online submissions for Complement of Base 10 Integer.

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        
        int n = 0;
        bool found = false;
        for (int i = 31; i >= 0; --i) {
            int j = 1 << i;
            if (found) {
                n |= (N & j) ? 0 : j;
            } else {
                found = N & j;
            }
        }
        return n;
    }
};