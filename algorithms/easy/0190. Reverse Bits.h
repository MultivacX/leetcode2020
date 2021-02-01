// 190. Reverse Bits

// Runtime: 4 ms, faster than 47.47% of C++ online submissions for Reverse Bits.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Reverse Bits.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 0;
        int j = 31;
        while (i < j) {
            if (1 << i & n) ans |= 1 << j;
            if (1 << j & n) ans |= 1 << i;
            ++i;
            --j;
        }
        return ans;
    }
};