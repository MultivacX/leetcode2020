// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

// Runtime: 16 ms, faster than 99.47% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 9.8 MB, less than 5.12% of C++ online submissions for Repeated Substring Pattern.

class Solution {
    bool check(const string& s, int m) {
        // printf("\nN:%d, m:%d:  \n", s.length(), m);
        for (int i = 0; i + m < s.length(); ++i) {
            // printf("%c|%c  ", s[i], s[i + m]);
            if (s[i] != s[i + m]) return false;
        }
        return true;
    }
    
public:
    bool repeatedSubstringPattern(string s) {
        const int N = s.length();
        int n = N;
        for (int m = 1; m * 2 <= N; ++m) 
            if (N % m == 0 && check(s, m))
                return true;
        return false;
    }
};