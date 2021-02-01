// 840. Magic Squares In Grid

// Runtime: 4 ms, faster than 74.23% of C++ online submissions for Magic Squares In Grid.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Magic Squares In Grid.

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
    
        int ans = 0;    
        for (int i = 0; i < M - 2; ++i)
            for (int j = 0; j < N - 2; ++j)
                if (isMagic(grid, i, j)) ++ans; 
        return ans;
    }
    
    bool isMagic(const vector<vector<int>>& grid, int i, int j) {
        vector<int> v(9, 0);
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                int val = grid[ii + i][jj + j];
                if (val < 1 || val > 9 || v[val - 1] > 0)
                    return false;
                v[val - 1] = val;
            }
        }
               
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        return sum == grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] 
            && sum == grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]
            
            && sum == grid[i][j] + grid[i+1][j] + grid[i+2][j] 
            && sum == grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] 
            && sum == grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2]
            
            && sum == grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]
            
            && sum == grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
    }
};