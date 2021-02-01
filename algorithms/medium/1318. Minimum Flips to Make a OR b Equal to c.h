// 1318. Minimum Flips to Make a OR b Equal to c

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Flips to Make a OR b Equal to c.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Minimum Flips to Make a OR b Equal to c.

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 31; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if ((bit_a | bit_b) == bit_c) continue;
            flips += abs(bit_a + bit_b - bit_c);
        }
        return flips;
    }
};