// 505. The Maze II
// https://leetcode.com/problems/the-maze-ii/

// Runtime: 88 ms, faster than 67.08% of C++ online submissions for The Maze II.
// Memory Usage: 20.3 MB, less than 84.62% of C++ online submissions for The Maze II.
    
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start[0] == destination[0] && start[1] == destination[1]) return 0;
        
        const int M = maze.size();
        const int N = maze[0].size();
        const int ti = destination[0];
        const int tj = destination[1];
        
        auto isWall = [&](int i, int j) {
            if (i < 0 || i >= M || j < 0 || j >= N) return true;
            if (maze[i][j] == 1) return true;
            return false;
        };
        
        if (isWall(ti - 1, tj) && isWall(ti + 1, tj) && 
            !isWall(ti, tj - 1) && !isWall(ti, tj + 1))
            return -1;
        if (!isWall(ti - 1, tj) && !isWall(ti + 1, tj) && 
            isWall(ti, tj - 1) && isWall(ti, tj + 1))
            return -1;
        
        const vector<vector<int>> ds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        vector<vector<int>> costs(M, vector<int>(N, INT_MAX));
        costs[start[0]][start[1]] = 0;
        
        using a3 = array<int, 3>;
        auto cmp = [](a3& l, a3& r) { return l[2] > r[2]; };
        priority_queue<a3, vector<a3>, decltype(cmp)> q(cmp);
        q.push({start[0], start[1], 0});
        
        while (!q.empty()) {
            int i = q.top()[0];
            int j = q.top()[1];
            int s = q.top()[2];
            q.pop();
            
            if (i == ti && j == tj) return s;
            
            for (int a = 0; a < 4; ++a) {
                const auto& d = ds[a];
                int ni = i, nj = j;
                while (!isWall(ni + d[0], nj + d[1]))
                    ni += d[0], nj += d[1];
                int ns = s + abs(ni - i) + abs(nj - j);
                if (ns < costs[ni][nj]) {
                    costs[ni][nj] = ns;
                    q.push({ni, nj, ns});
                }
            }
        }
        
        return costs[ti][tj] != INT_MAX ? costs[ti][tj] : -1;
    }
};

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

// WA
class Solution {
    const int U = 0;
    const int D = 1;
    const int L = 2;
    const int R = 3;
    const vector<int> fds = {1, 0, 3, 2}; 
    const vector<vector<int>> ds = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int N;
    int ans;
    int ti;
    int tj;
    
    // i*N+j, {U, D, L, R, step}
    unordered_map<int, array<int, 5>> m;
    
    bool isWall(const vector<vector<int>>& maze, int i, int j) {
        if (i < 0 || i >= maze.size() || j < 0 || j >= N) return true;
        if (maze[i][j] == 1) return true;
        return false;
    }
    
    void rolling(vector<vector<int>>& maze, int fi, int fj, int fd, int i, int j, int step) {
        if (isWall(maze, i, j)) return;
        
        if (i == ti && j == tj) {
            ans = min(ans, step);
            return;
        }
        
        int key = i * N + j;
        if (m.count(key) == 0) m.insert({key, {-1, -1, -1, -1, INT_MAX}});
        if (fd >= 0) m[key][fds[fd]] = fi * N + fj;
        if (m[key][4] <= step) return;
        m[key][4] = step;
        
        for (int a = 0; a < 4; ++a) {
            const auto& d = ds[a];
            int ni = i, nj = j;
            int nkey = m[key][a];
            if (nkey == -1) {
                while (!isWall(maze, ni + d[0], nj + d[1])) {
                    ni += d[0], nj += d[1];
                    nkey = ni * N + nj;
                } 
            } else { 
                ni = nkey / N;
                nj = nkey % N;
            }
            if (nkey == -1) continue;
            m[key][a] = nkey;
            rolling(maze, i, j, a, ni, nj, step + abs(i - ni) + abs(j - nj));
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start[0] == destination[0] && start[1] == destination[1]) return 0;
        
        N = maze[0].size();
        ans = INT_MAX;
        ti = destination[0];
        tj = destination[1];
        
        if (isWall(maze, ti - 1, tj) && 
            isWall(maze, ti + 1, tj) && 
            !isWall(maze, ti, tj - 1) && 
            !isWall(maze, ti, tj + 1))
            return -1;
        if (!isWall(maze, ti - 1, tj) && 
            !isWall(maze, ti + 1, tj) && 
            isWall(maze, ti, tj - 1) && 
            isWall(maze, ti, tj + 1))
            return -1;
        
        rolling(maze, -1, -1, -1, start[0], start[1], 0);
        // for (auto it : m) cout << it.first / N << ", " << it.first % N << " : " << it.second[4] << endl;
        return ans != INT_MAX ? ans : -1;
    }
};