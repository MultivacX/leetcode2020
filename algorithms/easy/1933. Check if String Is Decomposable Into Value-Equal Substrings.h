// 1933. Check if String Is Decomposable Into Value-Equal Substrings
// https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/

// Runtime: 4 ms, faster than 66.92% of C++ online submissions for Check if String Is Decomposable Into Value-Equal Substrings.
// Memory Usage: 6.6 MB, less than 18.80% of C++ online submissions for Check if String Is Decomposable Into Value-Equal Substrings.
    
class Solution {
public:
    bool isDecomposable(string s) {
        const int n = s.length();
        bool l2 = false;
        int l = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                ++l;
            } else if (l % 3 == 1) {
                return false;
            } else if (l % 3 == 2) {
                if (l2) {
                    return false;
                } else {
                    l2 = true;
                }
                l = 1;
            } else {
                l = 1;
            }
        }
        if (l % 3 == 1) {
            return false;
        } else if (l % 3 == 2) {
            if (l2) {
                return false;
            } else {
                l2 = true;
            }
        }
        return l2;
    }
};