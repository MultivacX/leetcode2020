// 1878. Get Biggest Three Rhombus Sums in a Grid
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

// Runtime: 296 ms, faster than 83.33% of C++ online submissions for Get Biggest Three Rhombus Sums in a Grid.
// Memory Usage: 58 MB, less than 50.00% of C++ online submissions for Get Biggest Three Rhombus Sums in a Grid.
    
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        map<int, int> sums;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ++sums[grid[i][j]];
                for (int h = 1; i + h * 2 < m && j - h >= 0 && j + h < n; ++h) {
                    int cur = grid[i][j] + grid[i + h * 2][j] +
                              grid[i + h][j - h] + grid[i + h][j + h];
                    for (int k = 1; k < h; ++k)
                        cur += grid[i + k][j - k] + grid[i + k][j + k] + 
                               grid[i + h * 2 - k][j - k] + grid[i + h * 2 - k][j + k];
                    ++sums[cur];
                }
            }
        }
        
        vector<int> ans;
        for (auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3; ++it) 
            //for (int i = 0; i < it->second && ans.size() < 3; ++i)
            ans.push_back(it->first);
        return ans;
    }
};