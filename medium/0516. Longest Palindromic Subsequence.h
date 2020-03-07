// 516. Longest Palindromic Subsequence

// Time Limit Exceeded
// 61 / 83 test cases passed.
/*class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int n = s.length();
        if (n <= 1) return n;
        if (n == 2) return s[0] == s[1] ? 2 : 1;
        if (s[0] == s[n - 1]) return 2 + longestPalindromeSubseq(s.substr(1, n - 2));
        return max(longestPalindromeSubseq(s.substr(0, n - 1)), longestPalindromeSubseq(s.substr(1)));
    }
};*/