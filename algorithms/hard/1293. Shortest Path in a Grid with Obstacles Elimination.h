// 1293. Shortest Path in a Grid with Obstacles Elimination
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

// Runtime: 180 ms, faster than 39.88% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
// Memory Usage: 56.2 MB, less than 29.60% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
    
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        visited[0][0] = vector<int>(k + 1);
        
        int level = 0;
        queue<vector<int>> q;
        q.push({0, 0, k});
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int ci = q.front()[0];
                int cj = q.front()[1];
                int ck = q.front()[2];
                q.pop();
                if (ci == m - 1 && cj == n - 1) 
                    return level;
                
                static const vector<int> d{0, 1, 0, -1, 0};
                for (int i = 0; i < 4; ++i) {
                    int ni = ci + d[i];
                    int nj = cj + d[i + 1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    if (grid[ni][nj] == 1 && ck == 0)
                        continue;
                    
                    int lv = level + 1;
                    int nk = ck - grid[ni][nj];
                    if (visited[ni][nj][nk] > lv) {
                        visited[ni][nj][nk] = lv;
                        q.push({ni, nj, nk});
                    }
                }
            }
            ++level;
        }
        
        return -1;
    }
};