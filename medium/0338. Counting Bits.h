// 338. Counting Bits

// Runtime: 52 ms, faster than 91.88% of C++ online submissions for Counting Bits.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Counting Bits.

class Solution {
public:
    vector<int> countBits(int num) {
        static const vector<int> m{0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        vector<int> ans(num + 1, 0);
        for (int i = 0; i <= num; ++i)
            for (int j = 0; j < 8 && (i >> (j * 4)); ++j)
                ans[i] += m[(i >> (j * 4)) & 0xf];
        return ans;
    }
};