// 1905. Count Sub Islands
// https://leetcode.com/problems/count-sub-islands/

// Runtime: 440 ms, faster than 80.00% of C++ online submissions for Count Sub Islands.
// Memory Usage: 145.1 MB, less than 60.00% of C++ online submissions for Count Sub Islands.
    
class Solution {
    int m;
    int n;
    
    // {island_mark, count}
    unordered_map<int, int> islands2;
    
    void getIsland2(vector<vector<int>>& grid2, int i, int j, int mark) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (grid2[i][j] != 1) return;
        
        grid2[i][j] = mark;
        ++islands2[mark];
        getIsland2(grid2, i - 1, j, mark);
        getIsland2(grid2, i + 1, j, mark);
        getIsland2(grid2, i, j - 1, mark);
        getIsland2(grid2, i, j + 1, mark);
    }
    
    void getIsland1(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, unordered_map<int, int>& subs) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (grid1[i][j] != 1) return;
        
        grid1[i][j] = -1;
        if (grid2[i][j] < 0) 
            ++subs[grid2[i][j]];
        getIsland1(grid1, grid2, i - 1, j, subs);
        getIsland1(grid1, grid2, i + 1, j, subs);
        getIsland1(grid1, grid2, i, j - 1, subs);
        getIsland1(grid1, grid2, i, j + 1, subs);
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] != 1) continue;
                getIsland2(grid2, i, j, -islands2.size() - 1);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid1[i][j] != 1) continue;
                unordered_map<int, int> subs;
                getIsland1(grid1, grid2, i, j, subs);
                for (const auto& [mark, count] : subs) {
                    auto it = islands2.find(mark);
                    if (it == islands2.end()) continue;
                    if (it->second == count) ++ans;
                    islands2.erase(it);
                }
            }
        }
        return ans;
    }
};