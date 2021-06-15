// 1895. Largest Magic Square
// https://leetcode.com/problems/largest-magic-square/

// Runtime: 20 ms, faster than 95.08% of C++ online submissions for Largest Magic Square.
// Memory Usage: 10.8 MB, less than 23.94% of C++ online submissions for Largest Magic Square.
    
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int>> rows(grid), cols(grid), dias(grid), ands(grid);
        
        for (int i = 0; i < m; ++i) 
            for (int j = 1; j < n; ++j)
                rows[i][j] += rows[i][j - 1];
        
        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i) 
                cols[i][j] += cols[i - 1][j];
        
        for (int i = 1; i < m; ++i) 
            for (int j = 1; j < n; ++j)
                dias[i][j] += dias[i - 1][j - 1];
        
        for (int i = 1; i < m; ++i) 
            for (int j = n - 2; j >= 0; --j)
                ands[i][j] += ands[i - 1][j + 1];
        
        auto rowSum = [&](int row, int left, int right){
            return rows[row][right] - (left > 0 ? rows[row][left - 1] : 0);
        };
        
        auto colSum = [&](int col, int top, int bottom){
            return cols[bottom][col] - (top > 0 ? cols[top - 1][col] : 0);
        };
        
        auto d0Sum = [&](int i, int j, int k){
            return dias[i][j] - (i > k && j > k ? dias[i - k - 1][j - k - 1] : 0);
        };
        
        auto d1Sum = [&](int i, int j, int k){
            return ands[i][j - k] - (i > k && j + 1 < n ? ands[i - k - 1][j + 1] : 0);
        };
        
        int ans = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int k = min(i, j);
                while (k >= ans) {
                    int d0 = d0Sum(i, j, k);
                    int d1 = d1Sum(i, j, k);
                    if (d0 != d1) { --k; continue; }
                    
                    bool b = true;
                    for (int r = i - k; r <= i & b; ++r)
                        if (rowSum(r, j - k, j) != d0)
                            b = false;
                    for (int c = j - k; c <= j & b; ++c)
                        if (colSum(c, i - k, i) != d0)
                            b = false;
                    
                    if (b) { ans = max(ans, ++k); break; }
                    else { --k; }
                }
            }
        }
        return ans;
    }
};