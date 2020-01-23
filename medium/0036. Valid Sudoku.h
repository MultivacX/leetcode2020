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