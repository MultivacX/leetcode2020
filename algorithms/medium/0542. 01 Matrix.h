// 542. 01 Matrix

// Runtime: 184 ms, faster than 84.58% of C++ online submissions for 01 Matrix.
// Memory Usage: 20.8 MB, less than 100.00% of C++ online submissions for 01 Matrix.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) {
                    int left = j < 1 ? 20000 : (matrix[i][j - 1] + 1);
                    int top = i < 1 ? 20000 : (matrix[i - 1][j] + 1);
                    matrix[i][j] = min(left, top);
                }
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] != 0) {
                    int right = j + 1 >= n ? 20000 : (matrix[i][j + 1] + 1);
                    int bottom = i + 1 >= m ? 20000 : (matrix[i + 1][j] + 1);
                    matrix[i][j] = min(matrix[i][j], min(right, bottom));
                }
            }
        }
        
        return matrix;
    }
};