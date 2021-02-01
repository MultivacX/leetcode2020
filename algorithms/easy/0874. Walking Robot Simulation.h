// 874. Walking Robot Simulation

// Runtime: 172 ms, faster than 75.94% of C++ online submissions for Walking Robot Simulation.
// Memory Usage: 33.2 MB, less than 100.00% of C++ online submissions for Walking Robot Simulation.

// Time Complexity: O(obstacles.size() + sum(commands[i] < 0 ? 1 : commands[i])).
// Space Complexity: O(obstacles.size()).

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int64_t> s;
        for (const auto& o : obstacles) s.insert((o[0] + 30000) * (int64_t)60001 + (o[1] + 30000));
        
        static const vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // static const int N = 0;
        // static const int E = 1;
        // static const int S = 2;
        // static const int W = 3;
        
        int ans = 0;
        int x = 0;
        int y = 0;
        int d = 0;
        for (int c : commands) {
            if (c == -2) {
                d = (d + 3) % 4;
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 1; i <= c; ++i) {
                    int tx = x + directions[d][0];
                    int ty = y + directions[d][1];
                    if (s.count((tx + 30000) * (int64_t)60001 + (ty + 30000)) == 0) {
                        x = tx;
                        y = ty;
                        ans = max(ans, x * x + y * y);        
                    } else break;
                }
            }
        }
        return ans;
    }
};