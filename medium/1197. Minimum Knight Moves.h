// 1197. Minimum Knight Moves
// https://leetcode.com/problems/minimum-knight-moves/

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