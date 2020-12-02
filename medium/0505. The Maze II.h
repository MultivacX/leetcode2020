// 505. The Maze II
// https://leetcode.com/problems/the-maze-ii/


// TLE 78 / 78 test cases passed, but took too long.
class Solution {
    unordered_map<int, int> m;
    int N;
    int ti;
    int tj;
    
    bool isWall(const vector<vector<int>>& maze, int i, int j) {
        if (i < 0 || i >= maze.size() || j < 0 || j >= N) return true;
        if (maze[i][j] == 1) return true;
        return false;
    }
    
    void moveOn(const vector<vector<int>>& maze, int ni, int nj, int path) {
        int key = ni * N + nj;
        auto it = m.find(key);
        if (it == m.end() || it->second > path) {
            m[key] = path;
            rolling(maze, ni, nj);
        }
    }
    
    void rolling(const vector<vector<int>>& maze, int i, int j) {
        if (isWall(maze, i, j)) return;
        
        int path = m[i * N + j];
        
        int step = 0;
        while (!isWall(maze, i - (++step), j));
        if (--step > 0) moveOn(maze, i - step, j, path + step);
        
        step = 0;
        while (!isWall(maze, i + (++step), j));
        if (--step > 0) moveOn(maze, i + step, j, path + step);
        
        step = 0;
        while (!isWall(maze, i, j - (++step)));
        if (--step > 0) moveOn(maze, i, j - step, path + step);
        
        step = 0;
        while (!isWall(maze, i, j + (++step)));
        if (--step > 0) moveOn(maze, i, j + step, path + step);
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        N = maze[0].size();
        ti = destination[0];
        tj = destination[1];
        m.insert({start[0] * N + start[1], 0});
        rolling(maze, start[0], start[1]);
        auto it = m.find(ti * N + tj);
        return it == m.end() ? -1 : it->second;
    }
};