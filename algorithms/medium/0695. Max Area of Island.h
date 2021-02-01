// 695. Max Area of Island

// Runtime: 16 ms, faster than 66.17% of C++ online submissions for Max Area of Island.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Max Area of Island.

// Runtime: O(M*N).
// Memory: O(1).

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M == 0) return 0;
        const int N = grid[0].size();
        if (N == 0) return 0;
        
        int area = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                area = max(area, get_area(grid, i, j));
            }
        }
        return area;
    }
    
    int get_area(vector<vector<int>>& grid, int i, int j) {
        const int M = grid.size();
        const int N = grid[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + get_area(grid, i - 1, j)
                 + get_area(grid, i + 1, j)
                 + get_area(grid, i, j - 1)
                 + get_area(grid, i, j + 1);
    }
};