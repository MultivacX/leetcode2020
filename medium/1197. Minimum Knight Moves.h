// 1197. Minimum Knight Moves
// https://leetcode.com/problems/minimum-knight-moves/

// Runtime: 1532 ms, faster than 9.56% of C++ online submissions for Minimum Knight Moves.
// Memory Usage: 53.3 MB, less than 29.15% of C++ online submissions for Minimum Knight Moves.
    
// A*
class Solution {
public:
    int minKnightMoves(int x, int y) {
        unordered_set<int> visited;
        
        auto canMove = [&](int x, int y) {
            if (abs(x) + abs(y) > 300) return false;
            return visited.insert(((x + 600) << 12) | (y + 600)).second;
        };
        
        canMove(0, 0);
        
        auto distance = [&](int x0, int y0) {
            int a = x0 - x, b = y0 - y;
            return (int)sqrt(a * a + b * b);
        };
        
        using a4 = array<int, 4>;
        auto cmp = [](a4& l, a4& r) { return (l[2] * 3 + l[3]) > (r[2] * 3 + r[3]); };
        priority_queue<a4, vector<a4>, decltype(cmp)> q(cmp);
        q.push({0, 0, 0, distance(0, 0)});
        
        while (!q.empty()) {
            int cx = q.top()[0];
            int cy = q.top()[1];
            int cs = q.top()[2];
            int ch = q.top()[3];
            q.pop();
            
            if (cx == x && cy == y) return cs;
            
            static const vector<vector<int>> moves{
                {2, 1}, {-2, -1}, {-2, 1}, {2, -1},
                {1, 2}, {-1, -2}, {-1, 2}, {1, -2},
            };
            for (const auto& m : moves) {
                int nx = cx + m[0];
                int ny = cy + m[1];
                if (!canMove(nx, ny)) continue;
                int ns = cs + 1;
                int nh = distance(nx, ny);
                q.push({nx, ny, ns, nh});
            }
        }
        return 0;
    }
};

// TLE
class Solution {
public:
    int minKnightMoves(int tx, int ty) {
        unordered_set<int> visited;
        auto canMove = [&](int x, int y) {
            static const int N = 350;
            if (x < -N || x > N || y < -N || y > N)
                return false;
            
            static const int mask = 0b1111111111111111;
            if (x < 0) x = (mask & x) | (1 << 15);
            else x = mask & x;
            if (y < 0) y = (mask & y) | (1 << 15);
            else y = mask & y;
            int v = (x << 16) | y;
            return visited.insert(v).second;
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited.insert(0);
        int step = 0;
        while (true) {
            int size = q.size();
            while (size-- > 0) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x == tx && y == ty) return step;
                
                static const vector<vector<int>> moves{
                    {2, 1}, {-2, -1}, {-2, 1}, {2, -1},
                    {1, 2}, {-1, -2}, {-1, 2}, {1, -2},
                };
                for (const auto& m : moves) {
                    int nx = x + m[0];
                    int ny = y + m[1];
                    if (!canMove(nx, ny))
                        continue;
                    q.push({nx, ny});
                }
            }
            ++step;
        }
        return step;
    }
};