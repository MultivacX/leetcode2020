// 354. Russian Doll Envelopes

// Runtime: 1876 ms, faster than 5.15% of C++ online submissions for Russian Doll Envelopes.
// Memory Usage: 16.7 MB, less than 47.70% of C++ online submissions for Russian Doll Envelopes.
    
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(rbegin(envelopes), rend(envelopes));
        const int N = envelopes.size();
        int ans = 0;
        vector<int> dp(N, 0);
        for (int i = N - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < N; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};