// 1771. Maximize Palindrome Length From Subsequences
// https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/

// Runtime: 180 ms, faster than 63.64% of C++ online submissions for Maximize Palindrome Length From Subsequences.
// Memory Usage: 56.8 MB, less than 81.82% of C++ online submissions for Maximize Palindrome Length From Subsequences.
    
class Solution {
    vector<vector<int>> memo1;
    vector<vector<int>> memo2;
    vector<vector<int>> memo;
    
    int helper(const string& word, int i, int j, vector<vector<int>>& m) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (m[i][j] != -1) return m[i][j];
        
        int ans = 0;
        if (word[i] != word[j]) 
            ans = max(helper(word, i + 1, j, m), helper(word, i, j - 1, m));
        else 
            ans = 2 + helper(word, i + 1, j - 1, m);
        return m[i][j] = ans;
    }
    
    int helper(const string& word1, const string& word2, int i, int j) {
        const int m = word1.length(), n = word2.length();
        if (j < 0) return helper(word1, i, m - 1, memo1);
        if (i >= m) return helper(word2, 0, j, memo2);
        if (memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        if (word1[i] != word2[j]) 
            ans = max(helper(word1, word2, i + 1, j), helper(word1, word2, i, j - 1));
        else
            ans = 2 + helper(word1, word2, i + 1, j - 1);
        return memo[i][j] = ans;
    }
    
public:
    int longestPalindrome(string word1, string word2) {
        const int m = word1.length(), n = word2.length();
        
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        memo1 = vector<vector<int>>(m, vector<int>(m, -1));
        memo2 = vector<vector<int>>(n, vector<int>(n, -1));
        
        // w1[i] == w2[j] : 
        // 2 + max(
        //        {w1[i+1] ... w2[j-1]}, 
        //        w1[i+1,m-1], 
        //        w2[0,j-1]
        //     )
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] != word2[j]) continue;
                ans = max(ans, 2 + helper(word1, word2, i + 1, j - 1));
            }
        }
        return ans;
    }
};