// 233. Number of Digit One
// https://leetcode.com/problems/number-of-digit-one/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Digit One.
// Memory Usage: 5.9 MB, less than 72.39% of C++ online submissions for Number of Digit One.
    
class Solution {
public:
    int countDigitOne(int n) {
        //     ab c def
        // 1.  00 1 000 ~ xy 1 uvw
        // 2.  ab 1 000 ~ ab 1 999
        
        // P = 1000                    No1@c in [0, 9999] = 1000 ~ 1999
        // abcdef / (P * 10) * P + min(P, max(abcdef % (P * 10) - P + 1, 0))
        // ab000 + min(1000, max(cdef - 1000 + 1, 0))
        
        int ans = 0;
        for (int64_t i = 1; i <= n; i *= 10) {
            int64_t ni = i * 10;
            ans += (n / ni) * i + min(i, max<int64_t>(n % ni - i + 1, 0));
        }
        return ans;
    }
};