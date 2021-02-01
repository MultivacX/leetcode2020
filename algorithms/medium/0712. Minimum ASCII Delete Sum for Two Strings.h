// 712. Minimum ASCII Delete Sum for Two Strings

// Runtime: 88 ms, faster than 8.61% of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.
// Memory Usage: 22.5 MB, less than 11.11% of C++ online submissions for Minimum ASCII Delete Sum for Two Strings.

// Runtime: O(M*N).
// Memory: O(M*N).

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int M = s1.length();
        const int N = s2.length();
        
        // find the max sum & longest sub seq
        vector<vector<pair<int, int>>> dp(M, vector<pair<int, int>>(N, {0, 0}));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s1[i] == s2[j]) {
                    dp[i][j].first = (i > 0 && j > 0 ? dp[i - 1][j - 1].first : 0) + 1;
                    dp[i][j].second = (i > 0 && j > 0 ? dp[i - 1][j - 1].second : 0) + s1[i];
                } else {
                    dp[i][j].first = max(j > 0 ? dp[i][j - 1].first : 0, i > 0 ? dp[i - 1][j].first : 0);
                    dp[i][j].second = max(j > 0 ? dp[i][j - 1].second : 0, i > 0 ? dp[i - 1][j].second : 0);
                }
            }   
        }
        int ans = -2 * dp[M - 1][N - 1].second;
        for (const char& c : s1) ans += c;
        for (const char& c : s2) ans += c;
        return ans;
    }
};