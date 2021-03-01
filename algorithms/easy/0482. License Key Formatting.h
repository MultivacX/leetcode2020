// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/

// Runtime: 8 ms, faster than 98.78% of C++ online submissions for License Key Formatting.
// Memory Usage: 8.7 MB, less than 5.83% of C++ online submissions for License Key Formatting.

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        const int N = S.length();
        string T;
        int i = N - 1;
        int k = 0;
        while (i >= 0) {
            char c = S[i--];
            if (c != '-') {
                T += toupper(c);
                if (++k == K) 
                    T += '-', k = 0;
            }
        }
        while (!T.empty() && T.back() == '-')
            T.pop_back();
        reverse(begin(T), end(T));
        return T;
    }
};


class Solution {
    char helper(char c) {
        if ('a' <= c && c <= 'z')
            return c - 'a' + 'A';
        return c;
    }
    
public:
    string licenseKeyFormatting(string S, int K) {
        const int n = S.length();
        string t;
        for (int i = n - 1, cnt = 0; i >= 0; --i) {
            if (S[i] != '-') {
                t += helper(S[i]);
                if (++cnt == K) {
                    t += '-';
                    cnt = 0;
                }
            }
        }
        while (t.back() == '-') t.pop_back();
        reverse(begin(t), end(t));
        return t;
    }
};