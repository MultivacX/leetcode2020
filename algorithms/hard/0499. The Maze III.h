// 499. The Maze III
// https://leetcode.com/problems/the-maze-iii/

// Runtime: 20 ms, faster than 77.39% of C++ online submissions for The Maze III.
// Memory Usage: 14.9 MB, less than 46.09% of C++ online submissions for The Maze III.
    
class Solution {
    struct Node {
        Node(int ii, int jj, int c, string w) 
        : i(ii), j(jj), cost(c), way(w) {}
        int i;
        int j;
        int cost;
        string way;
    };
    
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if (ball[0] == hole[0] && ball[1] == hole[1]) return 0;
        
        const int M = maze.size();
        const int N = maze[0].size();
        const int ti = hole[0];
        const int tj = hole[1];
        
        auto isWall = [&](int i, int j) {
            if (i < 0 || i >= M || j < 0 || j >= N) return true;
            if (maze[i][j] == 1) return true;
            return false;
        };
        
        const vector<vector<int>> ds = {{-1, 0, 'u'}, {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}};
        
        vector<vector<int>> costs(M, vector<int>(N, INT_MAX));
        vector<vector<string>> ways(M, vector<string>(N, ""));
        costs[ball[0]][ball[1]] = 0;
        
        auto cmp = [](Node& l, Node& r) { return l.cost > r.cost || (l.cost == r.cost && l.way > r.way); };
        priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);
        Node start(ball[0], ball[1], 0, "");
        q.push(start);
        
        while (!q.empty()) {
            int i = q.top().i;
            int j = q.top().j;
            int c = q.top().cost;
            string way(q.top().way);
            q.pop();

            for (int a = 0; a < 4; ++a) {
                const auto& d = ds[a];
                int ni = i, nj = j;
                string nw = way + (char)d[2];
                
                while (!isWall(ni + d[0], nj + d[1])) {
                    ni += d[0], nj += d[1];
                    if (ni == ti && nj == tj) {
                        int nc = c + abs(ni - i) + abs(nj - j);
                        if (nc < costs[ni][nj] || (nc == costs[ni][nj] && nw < ways[ni][nj])) {
                            costs[ni][nj] = nc;
                            ways[ni][nj] = nw;
                        }
                        ni = -1;
                        break;
                    }
                }
                if (ni < 0) continue;
                
                int nc = c + abs(ni - i) + abs(nj - j);
                if (nc < costs[ni][nj] || (nc == costs[ni][nj] && nw < ways[ni][nj])) {
                    costs[ni][nj] = nc;
                    ways[ni][nj] = nw;
                    Node node(ni, nj, nc, nw);
                    q.push(node);
                }
            }
        }
        
        return costs[ti][tj] != INT_MAX ? ways[ti][tj] : "impossible";
    }
};