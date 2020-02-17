// 97. Interleaving String

class Solution {
public:
    /*bool isInterleave(string s1, string s2, string s3) {
        const int l1 = s1.length();
        const int l2 = s2.length();
        const int l3 = s3.length();
        if (l1 + l2 != l3) return false;
        
        // length of interleaved
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        interleave(s1, s2, s3, dp, 0, 0, 0);
        return dp.back().back() == l3;
    }
    
    void interleave(const string& s1, 
                    const string& s2, 
                    const string& s3,
                    vector<vector<int>>& dp,
                    int i1,
                    int i2,
                    int i3) {
        static const int l1 = s1.length();
        static const int l2 = s2.length();
        static const int l3 = s3.length();
        
        if (i3 >= l3 || dp.back().back() == l3) return;
        if (i1 >= l1 || i2 >= l2) return;
            
        if (s1[i1] == s3[i3]) {
            dp[i1 + 1][i2] = dp[i1][i2] + 1;
            interleave(s1, s2, s3, dp, i1 + 1, i2, i3 + 1);
        }
        if (s2[i2] == s3[i3]) {
            dp[i1][i2 + 1] = dp[i1][i2] + 1;
            interleave(s1, s2, s3, dp, i1, i2 + 1, i3 + 1);
        }
    }*/
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