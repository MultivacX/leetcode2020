// 214. Shortest Palindrome

// Runtime: 88 ms, faster than 5.04% of C++ online submissions for Shortest Palindrome.
// Memory Usage: 712.9 MB, less than 7.14% of C++ online submissions for Shortest Palindrome.

// Time Complexity: O(n*n).
// Space Complexity: O(n).

class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.length();
        string r(rbegin(s), rend(s));
        if (s == r) return s;
        string L(s.substr(0, n - 1));
        for (int i = 0; i < n - 1; ++i) {
            if (L == r.substr(i + 1))
                return r.substr(0, i + 1) + s;
            L.pop_back();
        }
        return s;
    }
};