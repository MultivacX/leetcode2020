// 1301. Number of Paths with Max Score

// Runtime: 44 ms, faster than 28.80% of C++ online submissions for Number of Paths with Max Score.
// Memory Usage: 15.3 MB, less than 100.00% of C++ online submissions for Number of Paths with Max Score.

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        static const int modulo = 1000000007;
        
        const int M = board.size();
        const int N = board[0].length();
        
        vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(2, 0)));
        // dp[i][j] = {score, paths}
        int j = N - 1;
        for (int i = M - 2; i >= 0 && isdigit(board[i][j]); --i) {
            dp[i][j][0] = dp[i + 1][j][0] + board[i][j] - '0';
            dp[i][j][1] = 1;
            // printf("[%d,%d]:%d, ", i, j, dp[i][j][0]);
        }
        int i = M - 1;
        for (int j = N - 2; j >= 0 && isdigit(board[i][j]); --j) {
            dp[i][j][0] = dp[i][j + 1][0] + board[i][j] - '0';
            dp[i][j][1] = 1;
            // printf("[%d,%d]:%d, ", i, j, dp[i][j][0]);
        }
        
        dp[M - 1][N - 1][1] = 1;
        for (int i = M - 2; i >= 0; --i) {
            for (int j = N - 2; j >= 0; --j) {
                if (board[i][j] == 'X') continue;
                
                auto& cur = dp[i][j];
                auto& B = dp[i + 1][j];
                auto& R = dp[i][j + 1];
                auto& D = dp[i + 1][j + 1];
                
                int max_score = max(B[0], max(R[0], D[0]));
                int paths = 0;
                if (B[0] == max_score) paths = (paths + B[1]) % modulo;
                if (R[0] == max_score) paths = (paths + R[1]) % modulo;
                if (D[0] == max_score) paths = (paths + D[1]) % modulo;
                if (paths > 0) {
                    cur[0] = max_score + (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    cur[1] = paths;
                }
            }
        }
        return dp[0][0];
    }
};