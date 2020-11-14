// 788. Rotated Digits
// https://leetcode.com/problems/rotated-digits/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotated Digits.
// Memory Usage: 6.3 MB, less than 51.88% of C++ online submissions for Rotated Digits.

class Solution {
public:
    int rotatedDigits(int N) {
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            int n = i;
            int self = 0;
            int mirror = 0;
            int error = 0;
            while (n > 0) {
                int x = n % 10;
                if (x == 3 || x == 4 || x == 7) { ++error; break; }
                else if (x == 0 || x == 1 || x == 8) { ++self; }
                else ++mirror;
                n /= 10;
            }
            if (error > 0 || mirror == 0) continue;
            ++ans;
        }
        return ans;
    }
};