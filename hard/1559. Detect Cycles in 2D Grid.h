// 1559. Detect Cycles in 2D Grid
// https://leetcode.com/problems/detect-cycles-in-2d-grid/

// Runtime: 756 ms, faster than 56.08% of C++ online submissions for Detect Cycles in 2D Grid.
// Memory Usage: 104.1 MB, less than 25.61% of C++ online submissions for Detect Cycles in 2D Grid.

class Solution {
    int m;
    int n;
    unordered_map<int, int> visited;
    
    void detect(vector<vector<char>>& grid, int i, int j, char c, int step, bool& found) {
        if (found || i < 0 || i >= m || j < 0 || j >= n) return;
        
        int idx = i * n + j;
        if (grid[i][j] == '0' && visited.count(idx) && visited[idx] + 2 < step) {
            // cout << c << ": " << i << "," << j << "  " << visited[idx] << " " << step << endl;
            found = true;
        } else if (grid[i][j] == c) {
            grid[i][j] = '0';
            visited.emplace(idx, step);
            // cout << c << ": " << i << "," << j << "  " << visited[idx] << " " << step << endl;
            ++step;
            detect(grid, i - 1, j, c, step, found);
            detect(grid, i + 1, j, c, step, found);
            detect(grid, i, j - 1, c, step, found);
            detect(grid, i, j + 1, c, step, found);
        }
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                bool found = false;
                visited.clear();
                detect(grid, i, j, grid[i][j], 0, found);
                if (found) {
                    // for (int ii = 0; ii < m; ++ii) {
                    //     for (int jj = 0; jj < n; ++jj) {
                    //         cout << grid[ii][jj] << ' ';
                    //     }
                    //     cout << endl;
                    // }
                    return true;
                }
            }
        }
        return false;
    }
};