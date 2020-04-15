// 1314. Matrix Block Sum

// Runtime: 36 ms, faster than 31.63% of C++ online submissions for Matrix Block Sum.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Matrix Block Sum.

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int M = mat.size();
        const int N = mat[0].size();
        
        vector<vector<int>> RK(M, vector<int>(N, 0));
        // RK[i][j] = mat[i][j - K] + ... + mat[i][j + K]
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j == 0) {
                    for (int k = max(j - K, 0); k <= min(j + K, N - 1); ++k) {
                        RK[i][j] += mat[i][k];
                    }
                } else {
                    RK[i][j] = RK[i][j - 1] - (j - 1 - K >= 0 ? mat[i][j - 1 - K] : 0) + (j + K < N ? mat[i][j + K] : 0);
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << RK[i][j] << ", ";
            }
            cout << endl;
        }
        
        vector<vector<int>> ans(M, vector<int>(N, 0));
        // ans[i][j] = ans[i - 1][j] - RK[i - 1 - K][j] + RK[i + K][j]
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                if (i == 0) {
                    for (int k = max(i - K, 0); k <= min(i + K, M - 1); ++k) {
                        ans[i][j] += RK[k][j];
                    }
                } else {
                    ans[i][j] = ans[i - 1][j] - (i - 1 - K >= 0 ? RK[i - 1 - K][j] : 0) + (i + K < M ? RK[i + K][j] : 0);
                }
            }
        }
        return ans;
    }
};