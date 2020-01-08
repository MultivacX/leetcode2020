// 200. Number of Islands

// Runtime: 12 ms, faster than 92.48% of C++ online submissions for Number of Islands.
// Memory Usage: 10.6 MB, less than 98.88% of C++ online submissions for Number of Islands.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != '0') {
                    ++ans;
                    f(grid, i, j);            
                }
            }
        }
        return ans;
    }
    
    void f(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') 
            return;
        
        grid[i][j] = '0';
        f(grid, i - 1, j);
        f(grid, i + 1, j);
        f(grid, i, j - 1);
        f(grid, i, j + 1);
    }
};