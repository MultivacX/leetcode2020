// 1220. Count Vowels Permutation

// Runtime: 4 ms, faster than 96.10% of C++ online submissions for Count Vowels Permutation.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Count Vowels Permutation.

class Solution {
public:
    int countVowelPermutation(int n) {
        int size = dp[0].size();
        for (int k = size; k < n; ++k) {
            dp[a].push_back(dp[e][k - 1]);
            dp[e].push_back((dp[a][k - 1] + dp[i][k - 1]) % m);
            dp[i].push_back((dp[a][k - 1] + dp[e][k - 1] + dp[o][k - 1] + dp[u][k - 1]) % m);
            dp[o].push_back((dp[i][k - 1] + dp[u][k - 1]) % m);
            dp[u].push_back(dp[a][k - 1]);
        }
        
        return (dp[a][n - 1] + dp[e][n - 1] + dp[i][n - 1] + dp[o][n - 1] + dp[u][n - 1]) % m;
    }
    
    static const unsigned m = 1000000007;
    static const int a = 0;
    static const int e = 1;
    static const int i = 2;
    static const int o = 3;
    static const int u = 4;
    static vector<vector<unsigned>> dp;
};
vector<vector<unsigned>> Solution::dp{{1}, {1}, {1}, {1}, {1}};