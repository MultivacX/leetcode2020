// 529. Minesweeper

// Runtime: 56 ms, faster than 47.81% of C++ online submissions for Minesweeper.
// Memory Usage: 12.5 MB, less than 100.00% of C++ online submissions for Minesweeper.

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int M = board.size();
        const int N = board[0].size();
        for (int k = 0; k < click.size(); k += 2) {
            int i = click[k];
            int j = click[k + 1];
            if (i < 0 || i >= M || j < 0 || j >= N) continue;
            if (board[i][j] == 'M') {
                board[i][j] = 'X';
                break;
            } else if (board[i][j] == 'E') {
                board[i][j] = 'B';
                deque<int> q;
                q.push_back(i * N + j);
                while (!q.empty()) {
                    int size = q.size();
                    while (size--) {
                        int cur_i = q.front() / N;
                        int cur_j = q.front() % N;
                        q.pop_front();
                        
                        static const vector<vector<int>> A{
                            {-1, -1}, {-1,  0}, {-1,  1},
                            { 0, -1},           { 0,  1},
                            { 1, -1}, { 1,  0}, { 1,  1},
                        };
                        
                        int mines = 0;
                        for (const auto& offset : A) {
                            int _i = cur_i + offset[0];
                            int _j = cur_j + offset[1];
                            if (_i < 0 || _i >= M || _j < 0 || _j >= N) continue;
                            if (board[_i][_j] == 'M') ++mines;
                        }
                        if (mines != 0) {
                            board[cur_i][cur_j] = '0' + mines;
                            continue;
                        }
                        
                        for (const auto& offset : A) {
                            int _i = cur_i + offset[0];
                            int _j = cur_j + offset[1];
                            if (_i < 0 || _i >= M || _j < 0 || _j >= N) continue;
                            if (board[_i][_j] == 'E') {
                                board[_i][_j] = 'B';
                                q.push_back(_i * N + _j);
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
};