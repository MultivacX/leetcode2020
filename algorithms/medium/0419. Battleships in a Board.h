// 419. Battleships in a Board

// Runtime: 8 ms, faster than 59.53% of C++ online submissions for Battleships in a Board.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Battleships in a Board.

// Time Complexity: O(M * N).
// Space Complexity: O(1).

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int M = board.size();
        if (M == 0) return 0;
        const int N = board[0].size();
        if (N == 0) return 0;
        
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') continue;
                if (i > 0 && board[i - 1][j] == 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                ++ans;
            }
        }
        return ans;
    }
};