// 461. Hamming Distance

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Hamming Distance.

class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int num = x ^ y;
        for (int i = 0; i < 32; ++i)
            if ((1 << i) & num)
                ++cnt;
        return cnt;
    }
};


class Solution {
public:
    int hammingDistance(int x, int y) {
        int d = 0;
        for (int z = 1; z <= 1 << 30 && z > 0; z <<= 1) {
            if ((z & x) != (z & y)) ++d;
            if (z >= x && z >= y) return d;
        }
        return d;
    }
};