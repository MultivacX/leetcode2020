// 794. Valid Tic-Tac-Toe State

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Tic-Tac-Toe State.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Valid Tic-Tac-Toe State.

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cntx = 0;
        int cnto = 0;
        for (const string& s : board)
            for (const char& c : s)
                if (c == 'X') ++cntx;
                else if (c == 'O') ++cnto;
        
        if (cntx < cnto || cntx > cnto + 1) return false;
        if (win(board, 'X') && cntx == cnto) return false;
        if (win(board, 'O') && cntx > cnto) return false;
        
        return true;
    }
    
    bool win(vector<string>& board, char c) {
        for (const string& s : board)
            if (s[0] == c && s[1] == c && s[2] == c) 
                return true;
        for (int i = 0; i < 3; ++i)
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
                return true;
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
            return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
            return true;
        return false;
    }
};