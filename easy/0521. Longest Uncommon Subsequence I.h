// 521. Longest Uncommon Subsequence I

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Uncommon Subsequence I .
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Longest Uncommon Subsequence I .

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a != b ? max(a.length(), b.length()) : -1;
    }
};