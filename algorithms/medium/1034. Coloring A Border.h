// 1034. Coloring A Border
// https://leetcode.com/problems/coloring-a-border/

// Runtime: 36 ms, faster than 70.06% of C++ online submissions for Coloring A Border.
// Memory Usage: 13.4 MB, less than 6.35% of C++ online submissions for Coloring A Border.

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        findBorder(grid, r0, c0, grid[r0][c0]);
        const int M = grid.size();
        const int N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) grid[i][j] = color;
                else if (grid[i][j] < 0) grid[i][j] *= -1;
            }
        }
        return grid;
    }
    
    void findBorder(vector<vector<int>>& grid, int r, int c, int cur_color) {
        const int M = grid.size();
        const int N = grid[0].size();
        
        if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] != cur_color) return;
        
        if (r == 0 || r == M - 1 || c == 0 || c == N - 1) grid[r][c] = 0;
        else if (r != 0     && abs(grid[r - 1][c]) != cur_color && grid[r - 1][c] != 0) grid[r][c] = 0;
        else if (r != M - 1 && abs(grid[r + 1][c]) != cur_color && grid[r + 1][c] != 0) grid[r][c] = 0;
        else if (c != 0     && abs(grid[r][c - 1]) != cur_color && grid[r][c - 1] != 0) grid[r][c] = 0;
        else if (c != N - 1 && abs(grid[r][c + 1]) != cur_color && grid[r][c + 1] != 0) grid[r][c] = 0;
        else grid[r][c] *= -1;
        
        findBorder(grid, r - 1, c, cur_color);
        findBorder(grid, r + 1, c, cur_color);
        findBorder(grid, r, c - 1, cur_color);
        findBorder(grid, r, c + 1, cur_color);
    }
};