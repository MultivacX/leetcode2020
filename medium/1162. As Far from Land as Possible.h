// 1162. As Far from Land as Possible
// https://leetcode.com/problems/as-far-from-land-as-possible/

// Runtime: 340 ms, faster than 26.26% of C++ online submissions for As Far from Land as Possible.
// Memory Usage: 115.6 MB, less than 5.04% of C++ online submissions for As Far from Land as Possible.

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != 1) continue;
                deque<int> q;
                q.push_back(i * N + j);
                int step = 0;
                while (!q.empty()) {
                    --step;
                    int size = q.size();
                    while (size--) {
                        int ii = q.front() / N;
                        int jj = q.front() % N;
                        q.pop_front();
                        
                        if (ii > 0 && (grid[ii - 1][jj] == 0 || grid[ii - 1][jj] < step)) { grid[ii - 1][jj] = step; q.push_back((ii - 1) * N + jj); }
                        if (ii + 1 < N && (grid[ii + 1][jj] == 0 || grid[ii + 1][jj] < step)) { grid[ii + 1][jj] = step; q.push_back((ii + 1) * N + jj); }
                        if (jj > 0 && (grid[ii][jj - 1] == 0 || grid[ii][jj - 1] < step)) { grid[ii][jj - 1] = step; q.push_back(ii * N + jj - 1); }
                        if (jj + 1 < N && (grid[ii][jj + 1] == 0 || grid[ii][jj + 1] < step)) { grid[ii][jj + 1] = step; q.push_back(ii * N + jj + 1); }
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // cout << grid[i][j] << " ";
                if (grid[i][j] >= 0) continue;
                ans = min(ans, grid[i][j]);
            }
            // cout << endl;
        }
        return ans == INT_MAX ? -1 : -ans;
    }
};