// 994. Rotting Oranges

// Runtime: 12 ms, faster than 23.36% of C++ online submissions for Rotting Oranges.
// Memory Usage: 9 MB, less than 93.75% of C++ online submissions for Rotting Oranges.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return -1;
        int n = grid[0].size();
        if (n == 0) return -1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rottingAdjacent(grid, i, j, 0);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
                ans = min(ans, grid[i][j]);
            }
        }
        return -ans;
    }
    
    void rottingAdjacent(vector<vector<int>>& grid, int i, int j, int step) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        if (step > 0 && grid[i][j] == 2) return;
        
        if (grid[i][j] == 1) {
            grid[i][j] = -step;
        } else if (grid[i][j] < 0) {
            if (grid[i][j] >= -step) return;
            grid[i][j] = -step;
        }
        
        ++step;
        rottingAdjacent(grid, i - 1, j, step);
        rottingAdjacent(grid, i + 1, j, step);
        rottingAdjacent(grid, i, j - 1, step);
        rottingAdjacent(grid, i, j + 1, step);
    }
};