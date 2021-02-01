// 361. Bomb Enemy
// https://leetcode.com/problems/bomb-enemy/

// Runtime: 92 ms, faster than 13.70% of C++ online submissions for Bomb Enemy.
// Memory Usage: 16.5 MB, less than 10.96% of C++ online submissions for Bomb Enemy.
    
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        const int M = grid.size();
        if (M == 0) return 0;
        const int N = grid[0].size();
        if (N == 0) return 0;
        
        unordered_map<int, array<int, 4>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0, k = 0; j < N; ++j) {
                if (grid[i][j] == '0') m[i * N + j][0] = k;
                else if (grid[i][j] == 'E') ++k;
                else k = 0;
            }
            for (int j = N - 1, k = 0; j >= 0; --j) {
                if (grid[i][j] == '0') m[i * N + j][1] = k;
                else if (grid[i][j] == 'E') ++k;
                else k = 0;
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0, k = 0; i < M; ++i) {
                if (grid[i][j] == '0') m[i * N + j][2] = k;
                else if (grid[i][j] == 'E') ++k;
                else k = 0;
            }
            for (int i = M - 1, k = 0; i >= 0; --i) {
                if (grid[i][j] == '0') m[i * N + j][3] = k;
                else if (grid[i][j] == 'E') ++k;
                else k = 0;
            }
        }
        
        int k = 0;
        for (const auto& it : m) 
            k = max(k, it.second[0] + it.second[1] + it.second[2] + it.second[3]);
        return k;
    }
};