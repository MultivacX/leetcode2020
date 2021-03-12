// 79. Word Search

// Runtime: 20 ms, faster than 96.46% of C++ online submissions for Word Search.
// Memory Usage: 10.1 MB, less than 98.53% of C++ online submissions for Word Search.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (check(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, const string& word, int wi) {
        if (word.length() == wi) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[wi]) return false;
        
        char c = board[i][j];
        board[i][j] = '#';
        bool ans = check(board, i - 1, j, word, wi + 1)
                || check(board, i + 1, j, word, wi + 1)
                || check(board, i, j - 1, word, wi + 1)
                || check(board, i, j + 1, word, wi + 1);
        board[i][j] = c;
        return ans;
    }
};


class Solution {
    int m;
    int n;
    
    bool search(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (k >= word.length()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;
        
        char t = board[i][j];
        board[i][j] = '#';
        if (search(board, word, i - 1, j, k + 1)) return true;
        if (search(board, word, i + 1, j, k + 1)) return true;
        if (search(board, word, i, j - 1, k + 1)) return true;
        if (search(board, word, i, j + 1, k + 1)) return true;
        board[i][j] = t;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (search(board, word, i, j, 0)) return true;
        return false;
    }
};