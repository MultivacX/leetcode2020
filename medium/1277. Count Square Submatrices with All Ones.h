// 1277. Count Square Submatrices with All Ones

// Runtime: 64 ms, faster than 71.08% of C++ online submissions for Count Square Submatrices with All Ones.
// Memory Usage: 14 MB, less than 100.00% of C++ online submissions for Count Square Submatrices with All Ones.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // matrix[i][j] as right bottom
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == 0) continue;
                int L = j > 0 ? matrix[i][j - 1] : 0;
                int U = i > 0 ? matrix[i - 1][j] : 0;
                int D = i > 0 && j > 0 ? matrix[i - 1][j - 1] : 0;
                int side = 1 + min({L, U, D});
                cnt += side;
                matrix[i][j] = side;
            }
        }
        return cnt;
    }
};