// 73. Set Matrix Zeroes

// Runtime: 44 ms, faster than 94.09% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 11.5 MB, less than 81.48% of C++ online submissions for Set Matrix Zeroes.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return;
        const int n = matrix[0].size();
        if (n == 0) return;
        
        bool row0 = false;
        for (int j = 0; j < n && !row0; ++j) 
            row0 = matrix[0][j] == 0;
        
        bool col0 = false;
        for (int i = 0; i < m && !col0; ++i) 
            col0 = matrix[i][0] == 0;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i < m && matrix[0][j] == 0; ++i) {
                matrix[i][j] = 0;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n && matrix[i][0] == 0; ++j) {
                matrix[i][j] = 0;
            }
        }
        
        for (int j = 0; j < n && row0; ++j) 
            matrix[0][j] = 0;
        
        for (int i = 0; i < m && col0; ++i) 
            matrix[i][0] = 0;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool r0 = false, c0 = false;
        bool rm = false, cn = false;
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) r0 = true;
            if (matrix[m - 1][j] == 0) rm = true;
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) c0 = true;
            if (matrix[i][n - 1] == 0) cn = true;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (r0) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (rm) for (int j = 0; j < n; ++j) matrix[m - 1][j] = 0;
        if (c0) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        if (cn) for (int i = 0; i < m; ++i) matrix[i][n - 1] = 0;
    }
};