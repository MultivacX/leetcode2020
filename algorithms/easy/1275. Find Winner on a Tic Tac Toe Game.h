// 1275. Find Winner on a Tic Tac Toe Game
// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
// Memory Usage: 8.8 MB, less than 74.72% of C++ online submissions for Find Winner on a Tic Tac Toe Game.

class Solution {
    bool win(vector<vector<int>>& board, int c) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }
    
    bool full(vector<vector<int>>& board) {
        for (int i = 0; i < 3; ++i) 
            for (int j = 0; j < 3; ++j)
                if (!board[i][j])
                    return false;
        return true;
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3, 0));
        int p = 'A';
        for (const auto& m : moves) {
            board[m[0]][m[1]] = p;
            p = p != 'A' ? 'A' : 'B';
        }
        if (win(board, 'A')) return "A";
        if (win(board, 'B')) return "B";
        if (full(board)) return "Draw";
        return "Pending";
    }
};