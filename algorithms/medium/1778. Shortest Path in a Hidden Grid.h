// 1778. Shortest Path in a Hidden Grid

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