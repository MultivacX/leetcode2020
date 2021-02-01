// 1267. Count Servers that Communicate

// Runtime: 44 ms, faster than 96.85% of C++ online submissions for Count Servers that Communicate.
// Memory Usage: 15.2 MB, less than 100.00% of C++ online submissions for Count Servers that Communicate.

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> I(m, 0);
        vector<int> J(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                I[i] += grid[i][j];
                J[j] += grid[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (I[i] > 1 || J[j] > 1) ++ans;
            }
        }
        return ans;
    }
};