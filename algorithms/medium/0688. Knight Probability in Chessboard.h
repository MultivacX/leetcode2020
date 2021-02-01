// 688. Knight Probability in Chessboard
// https://leetcode.com/problems/knight-probability-in-chessboard/

// Runtime: 28 ms, faster than 28.89% of C++ online submissions for Knight Probability in Chessboard.
// Memory Usage: 8.3 MB, less than 38.92% of C++ online submissions for Knight Probability in Chessboard.

// Time Complexity: O(N * N * K).
// Space Complexity: O(N * N).

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        dp[r][c] = 1.0;
        while (K-- > 0) {
            static const vector<vector<int>> moves{
                {2, 1}, {2, -1}, {-2, 1}, {-2, -1},  
                {1, 2}, {1, -2}, {-1, 2}, {-1, -2},  
            };
            
            vector<vector<double>> cur(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (dp[i][j] <= 0) continue;
                    for (int k = 0; k < 8; ++k) {
                        int ii = moves[k][0] + i;
                        int jj = moves[k][1] + j;
                        if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
                        cur[ii][jj] += dp[i][j] / 8.0;
                    }
                }
            }
            dp = cur;
        }
        double p = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                p += dp[i][j];
            }
        }
        return p;
    }
};