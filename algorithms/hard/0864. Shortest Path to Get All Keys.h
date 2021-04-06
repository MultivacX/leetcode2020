// 864. Shortest Path to Get All Keys
// https://leetcode.com/problems/shortest-path-to-get-all-keys/

// Runtime: 60 ms, faster than 59.40% of C++ online submissions for Shortest Path to Get All Keys.
// Memory Usage: 18.9 MB, less than 57.31% of C++ online submissions for Shortest Path to Get All Keys.
    
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        int si = -1, sj = -1, keys = 0;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (grid[i][j] == '@') 
                    si = i, sj = j;
                else if ('a' <= grid[i][j] && grid[i][j] <= 'f') 
                    ++keys;
        if (si == -1) return -1;
        
        int tk = (1 << keys) - 1;
            
        int sv = (si * n + sj) << 6;
        queue<int> q;
        q.push(sv);
        unordered_set<int> visited{sv};
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int v = q.front(); q.pop();
                int i = (v >> 6) / n;
                int j = (v >> 6) % n;
                int k = v & 0b111111;
                if (k == tk) return step;    
                
                static const vector<int> ds{0, -1, 0, 1, 0};
                for (int d = 0; d < 4; ++d) {
                    int ni = i + ds[d];
                    int nj = j + ds[d + 1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    if (grid[ni][nj] == '#')
                        continue;
                    if ('A' <= grid[ni][nj] && grid[ni][nj] <= 'F') {
                        int door = 1 << (grid[ni][nj] - 'A');
                        if ((k & door) == 0)
                            continue;
                    }
                    
                    int nk = k;
                    if ('a' <= grid[ni][nj] && grid[ni][nj] <= 'f')
                        nk |= 1 << (grid[ni][nj] - 'a');
                    int nv = ((ni * n + nj) << 6) | nk;
                    if (!visited.insert(nv).second)
                        continue;
                    q.push(nv);
                }
            }
            ++step;
        }
        return -1;
    }
};