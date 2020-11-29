// 490. The Maze
// https://leetcode.com/problems/the-maze/

// Runtime: 68 ms, faster than 84.73% of C++ online submissions for The Maze.
// Memory Usage: 19.3 MB, less than 87.66% of C++ online submissions for The Maze.

class Solution {
    const vector<int> db = {0b00010, 0b00100, 0b01000, 0b10000};
    const vector<vector<int>> ds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int U = 0;
    const int D = 1;
    const int L = 2;
    const int R = 3;
    
    bool isWall(vector<vector<int>>& maze, int i, int j) {
        if (i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size()) return true;
        if (maze[i][j] == 1) return true;
        return false;
    }
    
    bool rolling(vector<vector<int>>& maze, int i, int j, int ti, int tj, int f) {
        if (isWall(maze, i, j)) return false;
        
        // start rolling
        if (f == -1) {
            for (int k = 0; k < 4; ++k) {
                if (maze[i][j] & db[k]) continue;
                maze[i][j] |= db[k];
                if (rolling(maze, i + ds[k][0], j + ds[k][1], ti, tj, k)) return true;    
            }
            return false;
        }
        
        // check wall
        if (isWall(maze, i + ds[f][0], j + ds[f][1])) {
            if (i == ti && j == tj) return true;
            
            int k = 0;
            if (f == U) k = D;
            else if (f == D) k = U;
            else if (f == L) k = R;
            else k = L;
            maze[i][j] |= db[k];
            for (int k = 0; k < 4; ++k) {
                if (maze[i][j] & db[k]) continue;
                maze[i][j] |= db[k];
                if (rolling(maze, i + ds[k][0], j + ds[k][1], ti, tj, k)) return true;    
            }
            return false;
        } else {
            return rolling(maze, i + ds[f][0], j + ds[f][1], ti, tj, f);
        }
    }
    
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return rolling(maze, start[0], start[1], destination[0], destination[1], -1);
    }
};