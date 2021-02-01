// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/

// Runtime: 12 ms, faster than 36.99% of C++ online submissions for Reverse String II.
// Memory Usage: 7.5 MB, less than 6.12% of C++ online submissions for Reverse String II.

class Solution {
public:
    string reverseStr(string s, int k) {
        const int N = s.length();
        if (k > 1)
        for (int i = 0; i < N; i += 2 * k) 
            reverse(begin(s) + i, i + k <= N ? begin(s) + i + k : end(s));
        return s;
    }
};