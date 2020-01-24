// 48. Rotate Image

// Runtime: 8 ms, faster than 13.88% of C++ online submissions for Rotate Image.
// Memory Usage: 9.1 MB, less than 68.29% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = n - 2 - i; j >= 0; --j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};