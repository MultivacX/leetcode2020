// 1391. Check if There is a Valid Path in a Grid

// Runtime: 476 ms, faster than 23.47% of C++ online submissions for Check if There is a Valid Path in a Grid.
// Memory Usage: 59.1 MB, less than 100.00% of C++ online submissions for Check if There is a Valid Path in a Grid.

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        if (M == 1 && N == 1) return true;
        return check(grid);
        
        // vector<vector<int>> visited(M, vector<int>(N, 0));
        // return check(grid, 0, 0, visited);
    }
    
    // bool check(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
    //     const int M = grid.size();
    //     const int N = grid[0].size();
    //     if (i == M - 1 && j == N - 1) return true;
    //     if (visited[i][j]) return false;
    //     visited[i][j] = true;
    //     static const int L = 0;
    //     static const int R = 1;
    //     static const int U = 2;
    //     static const int B = 3;
    //     static const vector<vector<int>> directions{/*L*/{0, -1}, /*R*/{0, 1}, /*U*/{-1, 0}, /*B*/{1, 0}};
    //     static const vector<vector<int>> types{/*L*/{1, 4, 6}, /*R*/{1, 3, 5}, /*U*/{2, 3, 4}, /*B*/{2, 5, 6}};
    //     static const vector<vector<int>> next{/*1*/{L, R}, /*2*/{U, B}, /*3*/{L, B}, /*4*/{R, B}, /*5*/{L, U}, /*6*/{R, U}};
    //     for (int idx : next[grid[i][j] - 1]) {
    //         int next_i = i + directions[idx][0];
    //         int next_j = j + directions[idx][1];
    //         if (next_i < 0 || next_i >= M || next_j < 0 || next_j >= N) continue;
    //         // printf("[%d,%d]%d -> [%d,%d]%d:\n", i, j, grid[i][j], next_i, next_j, grid[next_i][next_j]);
    //         for (int t : types[idx]) {
    //             // cout << "    " << t << ", ";
    //             if (t == grid[next_i][next_j] && check(grid, next_i, next_j, visited))
    //                 return true;
    //         }
    //         // cout << endl;
    //     }
    //     return false;
    // }
    
    bool check(vector<vector<int>>& grid) {
        static const int L = 0;
        static const int R = 1;
        static const int U = 2;
        static const int B = 3;
        static const vector<vector<int>> directions{/*L*/{0, -1}, /*R*/{0, 1}, /*U*/{-1, 0}, /*B*/{1, 0}};
        static const vector<vector<int>> types{/*L*/{1, 4, 6}, /*R*/{1, 3, 5}, /*U*/{2, 3, 4}, /*B*/{2, 5, 6}};
        static const vector<vector<int>> next{/*1*/{L, R}, /*2*/{U, B}, /*3*/{L, B}, /*4*/{R, B}, /*5*/{L, U}, /*6*/{R, U}};
        
        const int M = grid.size();
        const int N = grid[0].size();
        
        vector<vector<int>> visited(M, vector<int>(N, 0));
        unordered_set<int> s{0};
        while (!s.empty()) {
            unordered_set<int> tmp;
            for (int x : s) {
                int i = x / N;
                int j = x % N;
                if (i == M - 1 && j == N - 1) return true;
                if (visited[i][j]) continue;
                visited[i][j] = true;
                for (int idx : next[grid[i][j] - 1]) {
                    int next_i = i + directions[idx][0];
                    int next_j = j + directions[idx][1];
                    if (next_i < 0 || next_i >= M || next_j < 0 || next_j >= N || visited[next_i][next_j]) continue;
                    for (int t : types[idx]) 
                        if (t == grid[next_i][next_j]) 
                            tmp.insert(next_i * N + next_j);
                }
            }
            s = tmp;
        }
        return false;
    }
};