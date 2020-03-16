// 980. Unique Paths III

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths III.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Unique Paths III.

class Solution {
public:
    int m = 0;
    int n = 0;
    int i_1 = -1;
    int j_1 = -1;
    // int i_2 = -1;
    // int j_2 = -1;
    int empty_squares = 0;
    int paths = 0;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++empty_squares;
                } else if (grid[i][j] == 1) {
                    i_1 = i;
                    j_1 = j;
                } /*else if (grid[i][j] == 2) {
                    i_2 = i;
                    j_2 = j;
                }*/
            }
        }
        
        walk(grid, i_1 - 1, j_1);
        walk(grid, i_1 + 1, j_1);
        walk(grid, i_1, j_1 - 1);
        walk(grid, i_1, j_1 + 1);
        
        return paths;
    }
    
    void walk(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) 
            return;
        
        if (grid[i][j] == 1 || grid[i][j] == -1) 
            return;
        
        if (empty_squares == 0 || grid[i][j] == 2) {
            if (empty_squares == 0 && grid[i][j] == 2) 
                ++paths;
            
            return;
        }
        
        grid[i][j] = -1;
        --empty_squares;
        
        walk(grid, i - 1, j);
        walk(grid, i + 1, j);
        walk(grid, i, j - 1);
        walk(grid, i, j + 1);
        
        grid[i][j] = 0;
        ++empty_squares;
    }
};