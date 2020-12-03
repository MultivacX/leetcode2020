// 694. Number of Distinct Islands
// https://leetcode.com/problems/number-of-distinct-islands/

// Runtime: 84 ms, faster than 37.86% of C++ online submissions for Number of Distinct Islands.
// Memory Usage: 32.7 MB, less than 48.17% of C++ online submissions for Number of Distinct Islands.

class Solution {
    int m;
    int n;
    unordered_set<string> islands;
    
    void dfs(vector<vector<int>>& grid, int si, int sj, int i, int j, ostringstream& s) {
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return;
        s << '(' << (i - si) << ',' << (j - sj) << ')';
        grid[i][j] = -1;
        s << 'u'; dfs(grid, si, sj, i - 1, j, s);
        s << 'd'; dfs(grid, si, sj, i + 1, j, s);
        s << 'l'; dfs(grid, si, sj, i, j - 1, s);
        s << 'r'; dfs(grid, si, sj, i, j + 1, s);
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ostringstream s;
                dfs(grid, i, j, i, j, s);
                if (!s.str().empty())
                    islands.insert(s.str());
            }
        }
        for (auto& s : islands) cout << s << endl;
        return islands.size();
    }
};