// 1139. Largest 1-Bordered Square

// Runtime: 36 ms, faster than 39.67% of C++ online submissions for Largest 1-Bordered Square.
// Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions for Largest 1-Bordered Square.

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        
        static const int L = 0;
        static const int R = 1;
        static const int U = 2;
        static const int B = 3;
        vector<vector<vector<int>>> m(M, vector<vector<int>>(N, vector<int>(4, 0)));
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                m[i][j][L] = 1 + (j >= 1 ?  m[i][j - 1][L] : 0);
                m[i][j][U] = 1 + (i >= 1 ?  m[i - 1][j][U] : 0);
            }
        }
        
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (grid[i][j] == 0) continue;
                m[i][j][R] = 1 + (j + 1 < N ?  m[i][j + 1][R] : 0);
                m[i][j][B] = 1 + (i + 1 < M ?  m[i + 1][j][B] : 0);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                // printf("[L:%d,R:%d][U:%d,B:%d] ", m[i][j][L], m[i][j][R], m[i][j][U], m[i][j][B]);
                if (grid[i][j] == 0) continue;
                
                int n = 1;
                int rb = min(m[i][j][R], m[i][j][B]);
                // printf("R:%d,B:%d \n", m[i][j][R], m[i][j][B]);
                for (int k = 1; k < rb && i + k < M && j + k < N; ++k) {
                    if (grid[i + k][j + k] == 0) continue;
                    int lu = min(m[i + k][j + k][U], m[i + k][j + k][L]);
                    // printf("    L:%d,U:%d  \n", m[i + k][j + k][L], m[i + k][j + k][U]);
                    if (lu < (k + 1)) continue;
                    n = max(n, (k + 1) * (k + 1));
                }
                ans = max(ans, n);
            }
            // cout << endl;
        }
        return ans;
    }
};