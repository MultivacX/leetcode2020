// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

// Runtime: 32 ms, faster than 87.85% of C++ online submissions for Minimum Cost to Make at Least One Valid Path in a Grid.
// Memory Usage: 16.8 MB, less than 59.28% of C++ online submissions for Minimum Cost to Make at Least One Valid Path in a Grid.
    
class Solution {
    int m;
    int n;
    queue<pair<int, int>> q;
    
    const vector<vector<int>> dir{
        {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}  
    };
    
    void dfs(const vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int cost) {
        if (i < 0 || i >= m || j < 0 || j >= n || dp[i][j] != INT_MAX) return;
        
        q.push({i, j});
        dp[i][j] = cost;
        dfs(grid, dp, i + dir[grid[i][j]][0], j + dir[grid[i][j]][1], cost);
    }
    
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        int cost = 0;
        dfs(grid, dp, 0, 0, cost);
        while (!q.empty()) {
            ++cost;
            int size = q.size();
            while (size-- > 0) {
                auto [i, j] = q.front(); q.pop();
                
                if (i == m - 1 && j == n - 1)
                    return dp[m - 1][n - 1];
                
                for (int d = 1; d <= 4; ++d) 
                    dfs(grid, dp, i + dir[d][0], j + dir[d][1], cost);
            }
        }
        return dp[m - 1][n - 1];
    }
};