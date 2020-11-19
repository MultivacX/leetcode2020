// 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Number with Alternating Bits.
// Memory Usage: 6.1 MB, less than 62.59% of C++ online submissions for Binary Number with Alternating Bits.

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n) {
            // cout << bitset<32>(n) << endl;
            // cout << bitset<32>(n & 0b11) << endl;
            // cout << bitset<32>(n & 0b111) << endl << endl;
            if ((n & 0b11) == 0b11) return false;
            if ((n & 0b111) == 0b100) return false;
            n >>= 1;
        }
        return true;
    }
};