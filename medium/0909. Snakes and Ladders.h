// 909. Snakes and Ladders
// https://leetcode.com/problems/snakes-and-ladders/

class Solution {
    void move(vector<vector<int>>& board, vector<int> dp, int i, int j) {

    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int N = board.size();
        vector<int> A(N * N + 1);
        // vector<vector<int>> B(N, vector<int>(N));
        for (int i = N - 1, l2r = 1, k = 1; i >= 0; --i) {
            if (l2r) {
                for (int j = 0; j < N; ++j) {
                    A[k] = i * N + j;
                    // B[i][j] = k;
                    ++k;
                }
            } else {
                for (int j = N - 1; j >= 0; --j) {
                    A[k] = i * N + j;
                    // B[i][j] = k;
                    ++k;
                }
            }
            l2r ^= 1;
        }
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j)
        //         printf("%3d ", B[i][j]);
        //     cout << endl;
        // }
        vector<int> dp(N * N + 1, INT_MAX);
        dp[0] = dp[1] = 0;
        for (int i = 2, step = 1; i <= N * N; i += 6, ++step) 
            for (int x = i; x <= i + 6 && x <= N * N; ++x) 
                dp[x] = step;
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j)
        //         printf("%3d ", dp[B[i][j]]);
        //     cout << endl;
        // }
        
        
        return dp[N * N];
    }
};