// 807. Max Increase to Keep City Skyline

// Runtime: 12 ms, faster than 62.59% of C++ online submissions for Max Increase to Keep City Skyline.
// Memory Usage: 10.4 MB, less than 6.45% of C++ online submissions for Max Increase to Keep City Skyline.

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M == 0) return 0;
        const int N = grid[0].size();
        if (N == 0) return 0;
        
        vector<int> rows(M, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                rows[i] = max(rows[i], grid[i][j]);
            }
        }
        
        vector<int> cols(N, 0);
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int h = max(min(rows[i], cols[j]), grid[i][j]);
                ans += h - grid[i][j];
            }
        }
        return ans;
    }
};