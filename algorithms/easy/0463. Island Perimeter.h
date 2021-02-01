// 463. Island Perimeter

// Runtime: 84 ms, faster than 38.35% of C++ online submissions for Island Perimeter.
// Memory Usage: 14.2 MB, less than 100.00% of C++ online submissions for Island Perimeter.

// Runtime: O(M*N).
// Memory: O(1).

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M == 0) return 0;
        const int N = grid[0].size();
        if (N == 0) return 0;
        
        int perimeter = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                perimeter = search(grid, i, j);
                if (perimeter > 0) return perimeter;
            }
        }
        return perimeter;
    }
    
    int search(vector<vector<int>>& grid, int i, int j) {
        const int M = grid.size();
        const int N = grid[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] != 1) return 0;
        grid[i][j] = -1;
        int perimeter = 0;
        if (i == 0 || grid[i - 1][j] == 0) ++perimeter;
        if (i == M - 1 || grid[i + 1][j] == 0) ++perimeter;
        if (j == 0 || grid[i][j - 1] == 0) ++perimeter;
        if (j == N - 1 || grid[i][j + 1] == 0) ++perimeter;
        return perimeter
            + search(grid, i - 1, j)
            + search(grid, i + 1, j)
            + search(grid, i, j - 1)
            + search(grid, i, j + 1);
    }
};