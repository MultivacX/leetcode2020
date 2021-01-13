// 1092. Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

// Runtime: 388 ms, faster than 8.53% of C++ online submissions for Shortest Common Supersequence .
// Memory Usage: 361.2 MB, less than 11.05% of C++ online submissions for Shortest Common Supersequence .
    
class Solution {
    string get_lcs(const string& str1, const string& str2) {
        const int M = str1.length();
        const int N = str2.length();
        vector<vector<string>> dp(M, vector<string>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i > 0 && dp[i - 1][j].length() > dp[i][j].length()) 
                    dp[i][j] = dp[i - 1][j];
                if (j > 0 && dp[i][j - 1].length() > dp[i][j].length())
                    dp[i][j] = dp[i][j - 1];
                if (str1[i] == str2[j]) {
                    if (i > 0 && j > 0 && dp[i - 1][j - 1].length() + 1 > dp[i][j].length()) 
                        dp[i][j] = dp[i - 1][j - 1] + str1[i];
                    else if (dp[i][j].empty())
                        dp[i][j] += str1[i];
                }
            }
        }
        return dp.back().back();
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = get_lcs(str1, str2);
        const int L = lcs.length();
        const int M = str1.length();
        const int N = str2.length();
        int i = 0, j = 0, k = 0;
        string ans;
        while (i < L || j < M || k < N) {
            if (i < L && j < M && k < N && lcs[i] == str1[j] && lcs[i] == str2[k]) {
                ans += lcs[i];
                ++i, ++j, ++k;
            } else {
                if (j < M && (i >= L || lcs[i] != str1[j])) ans += str1[j++];
                if (k < N && (i >= L || lcs[i] != str2[k])) ans += str2[k++];
            }
        }
        return ans;
    }
};