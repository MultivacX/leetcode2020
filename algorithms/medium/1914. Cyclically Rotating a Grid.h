// 1914. Cyclically Rotating a Grid
// https://leetcode.com/problems/cyclically-rotating-a-grid/

// Runtime: 24 ms, faster than 74.34% of C++ online submissions for Cyclically Rotating a Grid.
// Memory Usage: 15.8 MB, less than 6.05% of C++ online submissions for Cyclically Rotating a Grid.
    
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int M = grid.size();
        const int N = grid[0].size();
        
        for (int l = 0, m = M, n = N; l * 2 < min(M, N); ++l, --m, --n) {
            vector<int*> g;
            vector<int> v;
            // top
            for (int i = l, j = l; j < n; ++j) {
                g.push_back(&(grid[i][j]));
                v.push_back(grid[i][j]);
            }
            // right
            for (int i = l + 1, j = n - 1; i < m - 1; ++i) {
                g.push_back(&(grid[i][j]));
                v.push_back(grid[i][j]);
            }
            // bottom
            for (int i = m - 1, j = n - 1; j >= l; --j) {
                g.push_back(&(grid[i][j]));
                v.push_back(grid[i][j]);
            }
            // left
            for (int i = m - 2, j = l; i > l; --i) {
                g.push_back(&(grid[i][j]));
                v.push_back(grid[i][j]);
            }
            
            for (int i = k, j = 0; j < g.size(); ++i, ++j) {
                i = i % g.size();
                *(g[j]) = v[i];
            }
        }
        return grid;
    }
};