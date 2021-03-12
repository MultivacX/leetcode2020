// 191. Number of 1 Bits

// Runtime: 4 ms, faster than 65.73% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Number of 1 Bits.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        static const vector<int> m{0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        int ans = 0;
        for (int j = 0; j < 8 && (n >> (j * 4)); ++j)
            ans += m[(n >> (j * 4)) & 0xf];
        return ans;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) ++cnt;
            if (n < (1 << i)) return cnt;
        }
        return cnt;
    }
};