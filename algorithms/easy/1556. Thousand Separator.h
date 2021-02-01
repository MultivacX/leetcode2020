// 1556. Thousand Separator
// https://leetcode.com/problems/thousand-separator/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Thousand Separator.
// Memory Usage: 6.1 MB, less than 63.64% of C++ online submissions for Thousand Separator.

class Solution {
public:
    string thousandSeparator(int n) {
        string t(to_string(n));
        const int N = t.length();
        string s;
        int l = N % 3;
        if (l) s += t.substr(0, l);
        for (int j = l; j < N; j += 3) {
            if (!s.empty()) s += '.';
            s += t.substr(j, 3);
        }
        return s;
    }
};