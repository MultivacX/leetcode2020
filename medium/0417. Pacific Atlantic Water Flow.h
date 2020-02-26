// 417. Pacific Atlantic Water Flow

// Runtime: 60 ms, faster than 41.70% of C++ online submissions for Pacific Atlantic Water Flow.
// Memory Usage: 17.3 MB, less than 71.43% of C++ online submissions for Pacific Atlantic Water Flow.

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        const int M = matrix.size();
        if (M == 0) return {};
        const int N = matrix[0].size();
        if (N == 0) return {};
        
        vector<vector<bool>> visited_pacific(M, vector<bool>(N, false));
        deque<vector<int>> pacific;
        for (int i = 0; i < M; ++i) {
            pacific.push_back({i, 0});
            visited_pacific[i][0] = true;
        }
        for (int j = 0; j < N; ++j) {
            pacific.push_back({0, j});
            visited_pacific[0][j] = true;
        }
        flow(matrix, pacific, visited_pacific);
        
        vector<vector<bool>> visited_atlantic(M, vector<bool>(N, false));
        deque<vector<int>> atlantic;
        for (int i = 0; i < M; ++i) {
            atlantic.push_back({i, N - 1});
            visited_atlantic[i][N - 1] = true;
        }
        for (int j = 0; j < N; ++j) {
            atlantic.push_back({M - 1, j});
            visited_atlantic[M - 1][j] = true;
        }
        flow(matrix, atlantic, visited_atlantic);
        
        vector<vector<int>> ans;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visited_pacific[i][j] && visited_atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    
    void flow(const vector<vector<int>>& matrix, deque<vector<int>>& q, vector<vector<bool>>& visited) {
        static const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        const int M = matrix.size();
        const int N = matrix[0].size();
        
        while (!q.empty()) {
            int size = q.size();
            while (--size >= 0) {
                int row = q.front()[0];
                int col = q.front()[1];
                q.pop_front();
                
                for (int d = 0; d < 4; ++d) {
                    int r = row + directions[d][0];
                    int c = col + directions[d][1];
                    if (r < 0 || r >= M || c < 0 || c >= N || visited[r][c] || matrix[row][col] > matrix[r][c])
                        continue;
                    
                    q.push_back({ r, c });
                    visited[r][c] = true;
                }
            }
        }
        
        // for (int i = 0; i < M; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         printf("%d, ", visited[i][j] ? matrix[i][j] : 0);
        //     }
        //     printf("\n");
        // }
        // printf(" \n");
    }
};