// 1958. Check if Move is Legal
// https://leetcode.com/problems/check-if-move-is-legal/

// Runtime: 18 ms, faster than 6.47% of C++ online submissions for Check if Move is Legal.
// Memory Usage: 11.1 MB, less than 23.58% of C++ online submissions for Check if Move is Legal.
    
class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int l = 0, e = 0;
        for (int i = rMove, j = cMove - 1; j >= 0 && e == 0; --j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove, j = cMove + 1; j < 8 && e == 0; ++j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove - 1, j = cMove; i >= 0 && e == 0; --i) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove + 1, j = cMove; i < 8 && e == 0; ++i) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove - 1, j = cMove - 1; i >= 0 && j >= 0 && e == 0; --i, --j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove - 1, j = cMove + 1; i >= 0 && j < 8 && e == 0; --i, ++j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove + 1, j = cMove - 1; i < 8 && j >= 0 && e == 0; ++i, --j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        l = 0, e = 0;
        for (int i = rMove + 1, j = cMove + 1; i < 8 && j < 8 && e == 0; ++i, ++j) {
            if (board[i][j] == color) {
                e = 1;
                if (l > 0) return true;
            }
            if (board[i][j] == '.') break;
            ++l;
        }
        
        return false;
    }
};