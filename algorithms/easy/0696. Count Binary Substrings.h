// 696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/

// Runtime: 32 ms, faster than 45.16% of C++ online submissions for Count Binary Substrings.
// Memory Usage: 10.8 MB, less than 42.11% of C++ online submissions for Count Binary Substrings.

class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.length();
        int ans = 0;
        for (int i = 0; i + 1 < N; ++i) {
            int k = 0;
            while (s[i] != s[i + 1] &&
                   i - k >= 0 && 
                   i + 1 + k < N && 
                   s[i - k] == s[i] && 
                   s[i + 1 + k] == s[i + 1]) 
                ++k;
            ans += k;
        }
        return ans;
    }
};