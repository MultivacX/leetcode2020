// 934. Shortest Bridge

// Runtime: 40 ms, faster than 77.57% of C++ online submissions for Shortest Bridge.
// Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Shortest Bridge.

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        const int M = A.size();
        const int N = A[0].size();
        if (M == 1 && N == 1) return 1;
        
        deque<int> island;
        for (int i = 0; i < M && island.empty(); ++i) {
            for (int j = 0; j < N && island.empty(); ++j) {
                if (A[i][j] != 1) continue;
                find_island(A, i, j, island);
            }
        }
        
        int step = 0;
        while (!island.empty()) {
            int size = island.size();
            while (size--) {
                int i = island.front() / N;
                int j = island.front() % N;
                island.pop_front();
                
                static const vector<vector<int>> D{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (int k = 0; k < 4; ++k) {
                    int _i = i + D[k][0];
                    int _j = j + D[k][1];
                    if (_i < 0 || _i >= M || _j < 0 || _j >= N) continue;
                    if (A[_i][_j] == 0) {
                        A[_i][_j] = A[i][j] - 1;
                        island.push_back(_i * N + _j);
                    } else if (A[_i][_j] == 1) {
                        return step;
                    }
                }
            }
            ++step;
        }
        return step;
    }
    
    void find_island(vector<vector<int>>& A, int i, int j, deque<int>& island) {
        const int M = A.size();
        const int N = A[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N || A[i][j] != 1) return;
        
        A[i][j] = -1;
        island.push_back(i * N + j);
        
        find_island(A, i - 1, j, island);
        find_island(A, i + 1, j, island);
        find_island(A, i, j - 1, island);
        find_island(A, i, j + 1, island);
    }
};