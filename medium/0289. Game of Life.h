// 289. Game of Life

// Time Complexity: O(M * N).
// Space Complexity: O(1).

class Solution {
public:
    enum {
        dead = 0,
        live = 1,
        under_population = -1, // live + 0/1 -> dead
        next_generation  =  2, // live + 2/3 -> live
        over_population  = -4, // live +  4+ -> dead
        reproduction     =  3, // dead +   3 -> live  
    };
    
    void gameOfLife(vector<vector<int>>& board) {
        static const vector<vector<int>> directions{
            {-1, -1}, {-1, 0}, {-1, 1},  
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1},
        };
        
        static const int M = board.size();
        if (M == 0) return;
        static const int N = board[0].size();
        if (N == 0) return;
        
        // update
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int live_neighbors = 0;
                for (const auto& d : directions) {
                    int i_ = i + d[0];
                    int j_ = j + d[1];
                    if (i_ < 0 || i_ >= M || j_ < 0 || j_ >= N) continue;
                    if (board[i_][j_] == dead || board[i_][j_] == reproduction) continue;
                    ++live_neighbors;
                }
                
                if (board[i][j]) {
                    if (live_neighbors <= 1) board[i][j] = under_population;
                    else if (live_neighbors == 2 || live_neighbors == 3) board[i][j] = next_generation;
                    else if (live_neighbors >= 4) board[i][j] = over_population;
                } else if (live_neighbors == 3) {
                    board[i][j] = reproduction;
                }
            }    
        }
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                board[i][j] = board[i][j] > 0 ? 1 : 0;
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};