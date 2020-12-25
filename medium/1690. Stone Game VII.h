// 1690. Stone Game VII
// https://leetcode.com/problems/stone-game-vii/

// Runtime: 280 ms, faster than 60.49% of C++ online submissions for Stone Game VII.
// Memory Usage: 84.8 MB, less than 40.81% of C++ online submissions for Stone Game VII.
    
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        const int N = stones.size();
        vector<int> presums(N);
        presums[0] = stones[0];
        for (int i = 1; i < N; ++i)
            presums[i] = presums[i - 1] + stones[i];
        
        auto rangeSum = [&](int i, int j){
            return presums[j] - (i > 0 ? presums[i - 1] : 0);
        };
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = N - 2; i >= 0; --i) {
            for (int j = i + 1; j < N; ++j) {
                int a = rangeSum(i + 1, j) - dp[i + 1][j];
                int b = rangeSum(i, j - 1) - dp[i][j - 1];
                dp[i][j] = max(a, b);
            }
        }
        return dp[0][N - 1];
    }
};