// 1778. Shortest Path in a Hidden Grid
// https://leetcode.com/problems/shortest-path-in-a-hidden-grid/

// Runtime: 536 ms, faster than 100.00% of C++ online submissions for Shortest Path in a Hidden Grid.
// Memory Usage: 345.7 MB, less than 100.00% of C++ online submissions for Shortest Path in a Hidden Grid.
    
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    const char forward[4]  = {'U', 'D', 'L', 'R'};
    const char backward[4] = {'D', 'U', 'R', 'L'};
    const vector<vector<int>> offset = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}  
    };
    enum GridType {
        unvisited = -1,
        blocked = 0,
        empty = 1,
        target = 2,
        visited = 3
    };
    
    bool found = false;
    
    void dfs(GridMaster &master, vector<vector<int>>& grids, int i, int j) {
        grids[i][j] = empty;
        if (master.isTarget()) {
            grids[i][j] = target;
            found = true;
        }
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + offset[k][0];
            int nj = j + offset[k][1];
            if (grids[ni][nj] != unvisited) 
                continue;
            
            if (!master.canMove(forward[k])) {
                grids[ni][nj] = blocked;
            } else {
                master.move(forward[k]);
                dfs(master, grids, ni, nj);
                master.move(backward[k]);
            }
        }
    }
    
public:
    int findShortestPath(GridMaster &master) {
        vector<vector<int>> grids(1003, vector<int>(1003, unvisited));
        grids[500][500] = empty;
        dfs(master, grids, 500, 500);
        if (!found) return -1;
        
        int ans = 0;
        queue<vector<int>> q;
        q.push({500, 500});
        while (!q.empty()) {
            ++ans;
            int n = q.size();
            while (n-- > 0) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();
                if (grids[i][j] == visited)
                    continue;
                grids[i][j] = visited;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + offset[k][0];
                    int nj = j + offset[k][1];
                    if (grids[ni][nj] == target) 
                        return ans;
                    if (grids[ni][nj] == empty) 
                        q.push({ni, nj});
                }
            }
        }
        return ans;
    }
};

// TLE
class Solution {
    const char forward[4]  = {'U', 'D', 'L', 'R'};
    const char backward[4] = {'D', 'U', 'R', 'L'};
    const vector<vector<int>> offset = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0}  
    };
    
    int ans = INT_MAX;
    GridMaster* gm;
    unordered_map<int, unordered_set<int>> visited;
    
    bool canMove(char direction, char rollback, int x, int y) {
        return rollback != direction && 
               (visited.count(x) == 0 || visited[x].count(y) == 0) &&
               gm->canMove(direction);
    }
    
    int find(char rollback, int x, int y, int l) {
        if (l >= ans) return false;
        if (gm->isTarget()) { ans = l; return true; }
        
        visited[x].insert(y);
        for (int i = 0; i < 4; ++i) {
            int nx = x + offset[i][0];
            int ny = y + offset[i][1];
            if (canMove(forward[i], rollback, nx, ny)) {
                gm->move(forward[i]);
                find(backward[i], nx, ny, l + 1);
                gm->move(backward[i]);
            }
        }
        visited[x].erase(y);
        return false;
    }
    
public:
    int findShortestPath(GridMaster &master) {
        gm = &master;
        find('#', 0, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};