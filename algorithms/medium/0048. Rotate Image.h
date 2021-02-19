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

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int k = 0; k < n / 2; ++k) {
            const int L = n - 2 * k;
            for (int v = 0; v < L - 1; ++v) {
                int ti = k,             tj = k + v;
                int ri = k + v,         rj = k + L - 1;
                int bi = k + L - 1,     bj = k + L - 1 - v;
                int li = k + L - 1 - v, lj = k;
                
                int t = matrix[ti][tj];
                int r = matrix[ri][rj];
                int b = matrix[bi][bj];
                int l = matrix[li][lj];
                matrix[ti][tj] = l;
                matrix[ri][rj] = t;
                matrix[bi][bj] = r;
                matrix[li][lj] = b;
            }
        }
    }
};