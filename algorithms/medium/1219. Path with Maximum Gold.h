// 1219. Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/

// Runtime: 68 ms, faster than 83.42% of C++ online submissions for Path with Maximum Gold.
// Memory Usage: 7.6 MB, less than 5.03% of C++ online submissions for Path with Maximum Gold.

class Solution {
    int M;
    int N;
    
    int mine(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) return 0;
        
        int tmp = grid[i][j];
        grid[i][j] = 0;
        
        int ans = 0;
        ans = max(ans, mine(grid, i - 1, j));
        ans = max(ans, mine(grid, i + 1, j));
        ans = max(ans, mine(grid, i, j - 1));
        ans = max(ans, mine(grid, i, j + 1));
        
        grid[i][j] = tmp;
        return ans + tmp;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int ans = 0;
        for (int i = 0; i < M; ++i) 
            for (int j = 0; j < N; ++j) 
                ans = max(ans, mine(grid, i, j));
        return ans;
    }
};


// Runtime: 356 ms, faster than 9.50% of C++ online submissions for Path with Maximum Gold.
// Memory Usage: 167.5 MB, less than 5.03% of C++ online submissions for Path with Maximum Gold.

class Solution {
    int ans = 0;
    int M;
    int N;
    
    void mine(vector<vector<int>>& grid, int i, int j, int gold, unordered_set<int>& visited) {
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0 || visited.count(i * N + j)) return;
        
        gold += grid[i][j];
        ans = max(ans, gold);
        visited.insert(i * N + j);
        
        mine(grid, i - 1, j, gold, visited);
        mine(grid, i + 1, j, gold, visited);
        mine(grid, i, j - 1, gold, visited);
        mine(grid, i, j + 1, gold, visited);
        
        visited.erase(i * N + j);
        gold -= grid[i][j];
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) continue;
                int cnt = 0;
                cnt += i == 0     ? 0 : (grid[i - 1][j] == 0 ? 0 : 1);
                cnt += i == M - 1 ? 0 : (grid[i + 1][j] == 0 ? 0 : 1);
                cnt += j == 0     ? 0 : (grid[i][j - 1] == 0 ? 0 : 1);
                cnt += j == N - 1 ? 0 : (grid[i][j + 1] == 0 ? 0 : 1);
                if (cnt > 2) { 
                    ans = max(ans, grid[i][j]);
                } else { 
                    unordered_set<int> visited; 
                    mine(grid, i, j, 0, visited);
                }
            }
        }
        return ans;
    }
};
