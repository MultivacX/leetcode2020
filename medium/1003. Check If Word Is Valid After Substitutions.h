// 1003. Check If Word Is Valid After Substitutions
// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

// Runtime: 40 ms, faster than 37.54% of C++ online submissions for Check If Word Is Valid After Substitutions.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Check If Word Is Valid After Substitutions.

class Solution {
public:
    bool isValid(string S) {
        const int N = S.length();
        if (N % 3) return false;
        string T;
        for (char c : S) {
            int n = T.length();
            if (n >= 2 && c == 'c' && T[n - 2] == 'a' && T[n - 1] == 'b') {
                T.pop_back();
                T.pop_back();
            } else {
                T += c;
            }
        }
        return T.empty();
    }
};