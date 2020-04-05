// 74. Search a 2D Matrix

// Runtime: 12 ms, faster than 22.64% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) return false;
        const int n = matrix[0].size();
        if (n == 0) return false;
        // if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) return true;
            
            if (target < matrix[i][j]) --j;
            else ++i;
        }
        return false;
    }
};