// 317. Shortest Distance from All Buildings
// https://leetcode.com/problems/shortest-distance-from-all-buildings/

// Runtime: 232 ms, faster than 40.74% of C++ online submissions for Shortest Distance from All Buildings.
// Memory Usage: 22.2 MB, less than 58.63% of C++ online submissions for Shortest Distance from All Buildings.
    
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        
        int buildings = 0;
        vector<vector<int>> distances(M, vector<int>(N, 0));
        vector<vector<int>> counts(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 1) continue;
                
                ++buildings;
                
                vector<vector<bool>> visited(M, vector<bool>(N, false));
                int dist = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int size = q.size();
                    while (size-- > 0) {
                        int ci = q.front().first;
                        int cj = q.front().second;
                        q.pop();
                        
                        static const vector<vector<int>> directions{
                            {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
                        };
                        for (const auto& d : directions) {
                            int ni = ci + d[0];
                            int nj = cj + d[1];
                            if (ni < 0 || ni >= M || nj < 0 || nj >= N) continue;
                            if (grid[ni][nj] != 0 || visited[ni][nj]) continue;
                            visited[ni][nj] = true;
                            distances[ni][nj] += dist;
                            counts[ni][nj] += 1;
                            q.push({ni, nj});
                        }
                    }
                    ++dist;
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 0 || counts[i][j] != buildings) continue;
                ans = min(ans, distances[i][j]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};