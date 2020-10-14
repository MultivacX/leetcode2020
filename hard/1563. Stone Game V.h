// 1563. Stone Game V
// https://leetcode.com/problems/stone-game-v/

// Runtime: 788 ms, faster than 26.02% of C++ online submissions for Stone Game V.
// Memory Usage: 22.2 MB, less than 5.12% of C++ online submissions for Stone Game V.

class Solution {
    int calc(const vector<int>& prefixSums, int i, int j, vector<vector<int>>& dp) {
        if (i == j) return 0;
        if (dp[i][j] != 0) return dp[i][j];
        
        int ans = 0;
        for (int k = i; k < j; ++k) {
            // [i, k]
            int l = prefixSums[k] - (i == 0 ? 0 : prefixSums[i - 1]);
            // [k + 1, j]
            int r = prefixSums[j] - prefixSums[k];
            if (l < r) {
                ans = max(ans, l + calc(prefixSums, i, k, dp));
            } else if (l > r) {
                ans = max(ans, r + calc(prefixSums, k + 1, j, dp));
            } else {
                ans = max(ans, l + calc(prefixSums, i, k, dp));
                ans = max(ans, r + calc(prefixSums, k + 1, j, dp));
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        vector<int> prefixSums(N, 0);
        for (int i = 0; i < N; ++i) 
            prefixSums[i] = stoneValue[i] + (i == 0 ? 0 : prefixSums[i - 1]);
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        return calc(prefixSums, 0, N - 1, dp);
    }
};