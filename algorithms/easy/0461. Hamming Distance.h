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