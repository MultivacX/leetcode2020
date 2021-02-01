// 1254. Number of Closed Islands

// Runtime: 12 ms, faster than 82.52% of C++ online submissions for Number of Closed Islands.
// Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Number of Closed Islands.

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int j = 0; j < n; ++j) {
            setLand(grid, 0, j);
            setLand(grid, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            setLand(grid, i, 0);
            setLand(grid, i, n - 1);
        }
        
        int ans = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (setIsland(grid, i, j)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void setLand(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) return;
        
        grid[i][j] = -2;
        setLand(grid, i - 1, j);
        setLand(grid, i + 1, j);
        setLand(grid, i, j - 1);
        setLand(grid, i, j + 1);
    }
    
    bool setIsland(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 1 || i > m || j < 1 || j > n || grid[i][j] != 0) return false;
        
        grid[i][j] = -4;
        setIsland(grid, i - 1, j);
        setIsland(grid, i + 1, j);
        setIsland(grid, i, j - 1);
        setIsland(grid, i, j + 1);
        return true;
    }
};