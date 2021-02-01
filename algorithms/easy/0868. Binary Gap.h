// 868. Binary Gap
// https://leetcode.com/problems/binary-gap/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Gap.
// Memory Usage: 6.3 MB, less than 48.95% of C++ online submissions for Binary Gap.

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        for (int i = 0, j = 32; n > 0; ++i, n >>= 1) {
            if (n & 1) {
                if (ans < i - j)
                    ans = i - j;
                j = i;
            }
        }
        return ans;
    }
};