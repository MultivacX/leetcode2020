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