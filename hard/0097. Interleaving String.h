// 97. Interleaving String

// Runtime: 4 ms, faster than 79.95% of C++ online submissions for Interleaving String.
// Memory Usage: 9.1 MB, less than 7.14% of C++ online submissions for Interleaving String.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int l1 = s1.length();
        const int l2 = s2.length();
        const int l3 = s3.length();
        if (l1 + l2 != l3) return false;
        
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1 && s1[i - 1] == s3[i - 1]; ++i) {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (int j = 1; j <= l2 && s2[j - 1] == s3[j - 1]; ++j) {
            dp[0][j] = dp[0][j - 1] + 1;
        }
        
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                // cout << dp[i - 1][j] << ", " << s1[i - 1] << endl;
                if (s1[i - 1] == s3[dp[i - 1][j]]) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } 
                
                // cout << dp[i][j - 1] << ", " << s2[j - 1] << endl;
                if (s2[j - 1] == s3[dp[i][j - 1]]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        
        // for (int i = 0; i <= l1; ++i) {
        //     for (int j = 0; j <= l2; ++j) {
        //         cout << dp[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        
        return dp[l1][l2] == l3;
    }
};

// Time Limit Exceeded
// 101 / 101 test cases passed, but took too long.
/*class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int l1 = s1.length();
        const int l2 = s2.length();
        const int l3 = s3.length();
        return l1 + l2 == l3 && dfs(s1, s2, s3, 0, 0, 0);
    }
    
    bool dfs(const string& s1, const string& s2, const string& s3, int i1, int i2, int i3) {
        const int l1 = s1.length();
        const int l2 = s2.length();
        const int l3 = s3.length();
        
        if (i3 >= l3) return true;
        
        return (i1 < l1 && s1[i1] == s3[i3] && dfs(s1, s2, s3, i1 + 1, i2, i3 + 1)) ||
               (i2 < l2 && s2[i2] == s3[i3] && dfs(s1, s2, s3, i1, i2 + 1, i3 + 1));
    }
};*/