// 36. Valid Sudoku

// Runtime: 20 ms, faster than 36.81% of C++ online submissions for Valid Sudoku.
// Memory Usage: 9.4 MB, less than 97.44% of C++ online submissions for Valid Sudoku.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int row = 0;
            int col = 0;
            int square = 0;
            for (int j = 0; j < 9; ++j) {
                // row
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    if (row & (1 << v)) 
                        return false;
                    row |= (1 << v);
                }
                
                // col
                if (board[j][i] != '.') {
                    int v = board[j][i] - '0';
                    if (col & (1 << v)) 
                        return false;
                    col |= (1 << v);
                }
                
                // square
                int r = (i / 3) * 3 + (j / 3);
                int c = (i % 3) * 3 + (j % 3);
                //cout << r << "," << c << endl;
                if (board[r][c] != '.') {
                    int v = board[r][c] - '0';
                    if (square & (1 << v)) 
                        return false;
                    square |= (1 << v);
                }
            }
            //cout << "--" << endl;
        }
        
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int cnt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (++cnt[board[i][j] - '1'] > 1) return false;
            }
        }
        
        for (int j = 0; j < 9; ++j) {
            int cnt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                if (++cnt[board[i][j] - '1'] > 1) return false;
            }
        }
        
        static const int SubBox[9][2] = {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6},
        };
        for (int k = 0; k < 9; ++k) {
            int cnt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = SubBox[k][0]; i < SubBox[k][0] + 3; ++i) {
                for (int j = SubBox[k][1]; j < SubBox[k][1] + 3; ++j) {
                    if (board[i][j] == '.') continue;
                    if (++cnt[board[i][j] - '1'] > 1) return false;
                }
            }
        }
        
        return true;
    }
};