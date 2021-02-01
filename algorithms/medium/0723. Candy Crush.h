// 723. Candy Crush
// https://leetcode.com/problems/candy-crush/

// Runtime: 24 ms, faster than 64.15% of C++ online submissions for Candy Crush.
// Memory Usage: 9 MB, less than 57.39% of C++ online submissions for Candy Crush.
    
class Solution {
    bool crushNDrop(vector<vector<int>>& board) {
        const int M = board.size();
        const int N = board[0].size();
        
        auto crush = [&](int i, int j){
            if (board[i][j] == 0) 
                return false;
            int v = abs(board[i][j]);
            int u = i > 0     && abs(board[i - 1][j]) == v ? 1 : 0;
            int d = i + 1 < M && abs(board[i + 1][j]) == v ? 1 : 0;
            int l = j > 0     && abs(board[i][j - 1]) == v ? 1 : 0;
            int r = j + 1 < N && abs(board[i][j + 1]) == v ? 1 : 0;
            if (u + d == 2 || l + r == 2) {
                board[i][j] = -v;
                if (u + d == 2) board[i - 1][j] = -v;
                if (u + d == 2) board[i + 1][j] = -v;
                if (l + r == 2) board[i][j - 1] = -v;
                if (l + r == 2) board[i][j + 1] = -v;
                return true;
            }
            return false;
        };
        
        bool crushed = false;
        for (int i = M - 1; i >= 0; --i)
            for (int j = 0; j < N; ++j)
                if (crush(i, j)) 
                    crushed = true;
        // cout << "crush" << endl; for (int i = 0; i < M; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         printf("%4d ", board[i][j]);
        //     } cout << endl;
        // } cout << endl;
        if (!crushed) return false;
        
        for (int j = 0; j < N; ++j) {
            int i = M - 1;
            while (i >= 0 && board[i][j] > 0) --i;
            if (i < 0) continue;
            
            int k = i - 1;
            while (k >= 0) {
                if (board[k][j] > 0) 
                    swap(board[i--][j], board[k][j]);
                --k;
            }
            
            k = 0;
            while (k < M && board[k][j] <= 0) 
                board[k++][j] = 0;
        }
        // cout << "drop" << endl; for (int i = 0; i < M; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         printf("%4d ", board[i][j]);
        //     } cout << endl;
        // } cout << endl;
        return true;
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (crushNDrop(board));
        return board;
    }
};