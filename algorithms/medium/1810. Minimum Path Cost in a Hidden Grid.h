// 1810. Minimum Path Cost in a Hidden Grid
// https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/

// Runtime: 192 ms, faster than 100.00% of C++ online submissions for Minimum Path Cost in a Hidden Grid.
// Memory Usage: 46.4 MB, less than 100.00% of C++ online submissions for Minimum Path Cost in a Hidden Grid.

/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    const char forward[4]  = {'U', 'D', 'L', 'R'};
    const char backward[4] = {'D', 'U', 'R', 'L'};
    const vector<vector<int>> offset = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
    };
    
    const int n = 200;
    const int si = 100;
    const int sj = 100;
    const int sk = 100 * 200 + 100;
    
    int ti = -1;
    int tj = -1;
    
    unordered_map<int, int> grids{{sk, 0}};
    unordered_set<int> visited{sk + 100};
    
    void dfs(GridMaster &master, int i, int j) {
        if ((i == ti && j == tj) || master.isTarget()) {
            ti = i;
            tj = j;
        }
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + offset[k][0];
            int nj = j + offset[k][1];
            int nk = ni * n + nj;
            
            if (!visited.insert(nk).second) 
                continue;
            
            if (!master.canMove(forward[k])) 
                continue;
            
            grids.insert({nk, master.move(forward[k])});
            dfs(master, ni, nj);
            master.move(backward[k]);
        }
    }
    
public:
    int findShortestPath(GridMaster &master) {
        dfs(master, si, sj);
        if (ti == -1) return -1;
        
        visited.clear();
        visited.insert(sk);
        
        auto cmp = [](const auto& l, const auto& r){
            return l[1] > r[1];
        };
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> q(cmp);
        q.push({sk, 0});
        
        while (!q.empty()) {
            int i = q.top()[0] / n;
            int j = q.top()[0] % n;
            int w = q.top()[1];
            q.pop();
            if (i == ti && j == tj) return w;
            
            for (int k = 0; k < 4; ++k) {
                int ni = i + offset[k][0];
                int nj = j + offset[k][1];
                int nk = ni * n + nj;
                auto it = grids.find(nk);
                if (it == end(grids) || !visited.insert(nk).second)
                    continue;
                
                q.push({nk, w + it->second});
            }
        }
        
        return -1;
    }
};


// TLE
class Solution {
    const char forward[4]  = {'U', 'D', 'L', 'R'};
    const char backward[4] = {'D', 'U', 'R', 'L'};
    const vector<vector<int>> offset = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}  
    };
    
    const int n = 200;
    const int unvisited = -1;
    const int blocked = 0;
    
    const int si = 100;
    const int sj = 100;
    
    int ti = -1;
    int tj = -1;
    int ans = INT_MAX;
    
    void dfs(GridMaster &master, vector<vector<int>>& grids, int i, int j, int path) {
        if (path >= ans) return;
        
        if ((i == ti && j == tj) || master.isTarget()) {
            ti = i;
            tj = j;
            ans = path;
            return;
        }
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + offset[k][0];
            int nj = j + offset[k][1];
            
            if (grids[ni][nj] != unvisited) 
                continue;
            
            if (!master.canMove(forward[k])) {
                grids[ni][nj] = blocked;
            } else {
                grids[ni][nj] = master.move(forward[k]);
                dfs(master, grids, ni, nj, path + grids[ni][nj]);
                master.move(backward[k]);
                grids[ni][nj] = unvisited;
            }
        }
    }
    
public:
    int findShortestPath(GridMaster &master) {
        vector<vector<int>> grids(n, vector<int>(n, unvisited));
        grids[si][sj] = n;
        dfs(master, grids, si, sj, 0);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};