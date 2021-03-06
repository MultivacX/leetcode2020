// 1682. Longest Palindromic Subsequence II
// https://leetcode.com/problems/longest-palindromic-subsequence-ii/

// Runtime: 788 ms, faster than 33.48% of C++ online submissions for Longest Palindromic Subsequence II.
// Memory Usage: 258.8 MB, less than 30.40% of C++ online submissions for Longest Palindromic Subsequence II.
    
class Solution {
    int helper(const string& s, vector<vector<vector<int>>>& memo, int i, int j, char pre) {
        if (i >= j) return 0;
        
        int k = pre - 'a';
        if (memo[i][j][k] >= 0) return memo[i][j][k];
        
        int ans = 0;
        if (s[i] == s[j]) {
            if (pre == s[i]) {
                ans = max(helper(s, memo, i + 1, j, pre), helper(s, memo, i, j - 1, pre));
            } else {
                ans = 2 + helper(s, memo, i + 1, j - 1, s[i]);   
            }
        } else {
            ans = max(helper(s, memo, i + 1, j, pre), helper(s, memo, i, j - 1, pre));
        }
        memo[i][j][k] = ans;
        return ans;
    }
    
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(N, vector<int>(27, -1)));
        return helper(s, memo, 0, N - 1, 'a' + 26);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();
        vector<vector<int>> bits(N + 1, vector<int>(N + 1, 0));
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = N - 1; j > i; --j) {
                int k = N - 1 - j;
                if (s[i] == s[j]) {
                    int bit = 1 << (s[i] - 'a');
                    bits[i + 1][k + 1] = bit;
                    dp[i + 1][k + 1] = dp[i][k] + 1;
                    if (ans == 0) ans = 2;
                    if (bits[i][k] && (bits[i][k] & bit) == 0) 
                        ans = max(ans, dp[i + 1][k + 1] * 2);
                } else {
                    if (dp[i + 1][k] == dp[i][k + 1]) {
                        bits[i + 1][k + 1] = bits[i + 1][k] | bits[i][k + 1];
                    }
                    dp[i + 1][k + 1] = max(dp[i + 1][k], dp[i][k + 1]);
                }
            }
        }
        return ans;
    }
};

// WA: No two consecutive characters are equal, except the two middle ones.
class Solution {
    int helper(const string& s, vector<vector<int>>& memo, int i, int j) {
        if (i >= j) return 0;
        if (memo[i][j] >= 0) return memo[i][j];
        int ans = 0;
        if (s[i] == s[j]) {
            ans = 2 + helper(s, memo, i + 1, j - 1);
        } else {
            ans = max(helper(s, memo, i + 1, j), helper(s, memo, i, j - 1));
        }
        memo[i][j] = ans;
        return ans;
    }
    
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return helper(s, memo, 0, N - 1);
    }
};