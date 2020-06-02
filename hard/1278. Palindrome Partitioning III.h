// 1278. Palindrome Partitioning III
// https://leetcode.com/problems/palindrome-partitioning-iii/

// Runtime: 12 ms, faster than 86.56% of C++ online submissions for Palindrome Partitioning III.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning III.

class Solution {
    int get_changes(const string& s, int i, int j) {
        if (i == j) return 0;
        int change = 0;
        while (i < j) {
            if (s[i] != s[j]) ++change;
            ++i;
            --j;
        }
        return change;
    }
    
public:
    int palindromePartition(string s, int k) {
        const int N = s.length();
        if (N == k) return 0;
        
        vector<vector<int>> changes(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                changes[i][j] = get_changes(s, i, j);
                // cout << changes[i][j] << " " << s.substr(i, j - i + 1) << endl;
            }
        }
        
        if (k == 1) return changes[0][N - 1];
        
        // dp[N][k] = min(dp[L][k-1] + changes[L][N-1]), k-1 <= L <= N-1
        vector<vector<int>> dp(N + 1, vector<int>(k + 1, N));
        for (int P = 1; P <= k; ++P) {
            for (int L = P; L <= N; ++L) {
                // dp[L][P] = min(dp[l][P-1] + changes[l][L-1])
                
                if (P == 1) {
                    dp[L][P] = changes[0][L - 1];
                    continue;
                } else if (L == P) {
                    dp[L][P] = 0;
                    continue;
                }
                
                for (int l = P - 1; l < L; ++l) {
                    dp[L][P] = min(dp[L][P], dp[l][P - 1] + changes[l][L - 1]);
                }
            }
        }
        return dp[N][k];
    }
};