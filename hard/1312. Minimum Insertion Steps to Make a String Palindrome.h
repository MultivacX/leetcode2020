// 1312. Minimum Insertion Steps to Make a String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Runtime: 92 ms, faster than 20.96% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
// Memory Usage: 27.1 MB, less than 47.92% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.

class Solution {
public:
    int minInsertions(string s) {
        // LCS
        const int N = s.length();
        int ans = N - 1;
        vector<vector<int>> lcs(N + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                
                int l = i - 1;
                int r = N - j;
                if (s[l] == s[r]) lcs[i][j] = max(lcs[i][j], 1 + lcs[i - 1][j - 1]);
                
                if (l == r) {
                    ans = min(ans, N - 1 - 2 * (lcs[i][j] - 1));
                } else if (l + 1 == r) {
                    ans = min(ans, N - 2 * lcs[i][j]);
                }
            }
        }
        return ans;
    }
};