// 1329. Sort the Matrix Diagonally

// Runtime: 28 ms, faster than 78.11% of C++ online submissions for Sort the Matrix Diagonally.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Sort the Matrix Diagonally.

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m = mat.size();
        if (m == 1) return mat;
        const int n = mat[0].size();
        if (n == 1) return mat;
        
        for (int i = 0; i < m; ++i) {
            int step = min(m - 1 - i, n - 1);
            qsort(mat, i, 0, i + step, step);
        }
        for (int j = 1; j < n; ++j) {
            int step = min(n - 1 - j, m - 1);
            qsort(mat, 0, j, step, j + step);
        }
        
        return mat;
    }
    
    void xsort(vector<vector<int>>& mat, int si, int sj, int ei, int ej) {
        // printf("[%d, %d] -> [%d, %d]\n", si, sj, ei, ej);
        
        vector<int> v(ei - si + 1, 0);
        for (int i = 0; i <= ei - si; ++i) v[i] = mat[si + i][sj + i];
        sort(begin(v), end(v));
        for (int i = 0; i <= ei - si; ++i) mat[si + i][sj + i] = v[i];
    }
    
    void qsort(vector<vector<int>>& mat, int si, int sj, int ei, int ej) {
        const int m = mat.size();
        const int n = mat[0].size();
        
        if (si >= ei || sj >= ej) return;
        
        int val = mat[ei][ej];
        int xi = si - 1;
        int xj = sj - 1;
        
        int step = 0;
        while (true) {
            int i = si + step;
            int j = sj + step;
            if (i >= m || j >= n) break;
            
            if (mat[i][j] < val) {
                ++xi;
                ++xj;
                swap(mat[i][j], mat[xi][xj]);
            }
            ++step;
        }
        ++xi;
        ++xj;
        swap(mat[ei][ej], mat[xi][xj]);
        
        qsort(mat, si, sj, xi - 1, xj - 1);
        qsort(mat, xi + 1, xj + 1, ei, ej);
    }
};