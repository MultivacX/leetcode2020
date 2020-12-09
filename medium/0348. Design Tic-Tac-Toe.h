// 348. Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/

// Runtime: 44 ms, faster than 33.05% of C++ online submissions for Design Tic-Tac-Toe.
// Memory Usage: 18.1 MB, less than 58.88% of C++ online submissions for Design Tic-Tac-Toe.
    
class TicTacToe {
    int N;
    vector<int> rows;
    vector<int> cols;
    int dias;
    int ants;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : N(n), rows(n, 0), cols(n, 0), dias(0), ants(0) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int v = player == 1 ? 1 : -1;
        
        rows[row] += v;
        if (abs(rows[row]) == N) return player;
            
        cols[col] += v;
        if (abs(cols[col]) == N) return player;
        
        if (row == col) dias += v;
        if (abs(dias) == N) return player;
        
        if (row + col == N - 1) ants += v;
        if (abs(ants) == N) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */