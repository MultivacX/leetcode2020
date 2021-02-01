// 1091. Shortest Path in Binary Matrix

// Runtime: 124 ms, faster than 31.56% of C++ online submissions for Shortest Path in Binary Matrix.
// Memory Usage: 22.4 MB, less than 100.00% of C++ online submissions for Shortest Path in Binary Matrix.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M == 0) return -1;
        const int N = grid[0].size();
        if (N == 0) return -1;
        if (grid[0][0] == 1 || grid[M - 1][N - 1] == 1) return -1;
        
        deque<vector<int>> q;
        q.push_back({0, 0});
        grid[0][0] = -1;
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop_front();
                if (i == M - 1 && j == N - 1) return step;
                
                static const vector<vector<int>> D{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
                for (const auto& d : D) {
                    int ii = i + d[0];
                    int jj = j + d[1];
                    if (ii < 0 || ii >= M || jj < 0 || jj >= N || grid[ii][jj] != 0) continue;
                    
                    grid[ii][jj] = -1;
                    q.push_back({ii, jj});
                }
            }
            ++step;
        }
        return -1;
    }
};