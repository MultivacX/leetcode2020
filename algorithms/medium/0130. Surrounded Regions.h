// 130. Surrounded Regions

// Runtime: 20 ms, faster than 99.40% of C++ online submissions for Surrounded Regions.
// Memory Usage: 17 MB, less than 6.25% of C++ online submissions for Surrounded Regions.

class Solution {
public:
    int m;
    int n;
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        if (n == 0) return;
        
        for (int i = 0; i < m; ++i) {
            change(board, i, 0, 'O', 'I');
            change(board, i, n - 1, 'O', 'I');
        }
        for (int j = 1; j < n - 1; ++j) {
            change(board, 0, j, 'O', 'I');
            change(board, m - 1, j, 'O', 'I');
        }
        
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                change(board, i, j, 'O', 'X');
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                change(board, i, j, 'I', 'O');
            }
        }
    }
    
    void change(vector<vector<char>>& board, int i, int j, char from, char to) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != from) return;
        
        board[i][j] = to;
        
        change(board, i - 1, j, from, to);
        change(board, i + 1, j, from, to);
        change(board, i, j - 1, from, to);
        change(board, i, j + 1, from, to);
    }
};


class Solution {
public:
    int m;
    int n;
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        if (n == 0) return;
        
        for (int i = 0; i < m; ++i) {
            change(board, i, 0);
            change(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            change(board, 0, j);
            change(board, m - 1, j);
        }
        
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 1; i < m - 1; ++i) 
            for (int j = 1; j < n - 1; ++j) 
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (board[i][j] == 'I')
                    board[i][j] = 'O';
    }
    
    void change(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        
        board[i][j] = 'I';
        
        change(board, i - 1, j);
        change(board, i + 1, j);
        change(board, i, j - 1);
        change(board, i, j + 1);
    }
};