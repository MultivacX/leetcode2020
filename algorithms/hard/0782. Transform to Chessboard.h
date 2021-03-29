// 782. Transform to Chessboard
// https://leetcode.com/problems/transform-to-chessboard/

// Runtime: 12 ms, faster than 43.18% of C++ online submissions for Transform to Chessboard.
// Memory Usage: 10 MB, less than 97.73% of C++ online submissions for Transform to Chessboard.
    
class Solution {
    int check(const vector<vector<int>>& board, vector<int>& nums, bool row) {
        const int N = board.size();
        
        auto value = [](const vector<vector<int>>& board, bool row, int i, int j){
            return row ? board[i][j] : board[j][i];
        };
        
        int rowA = 0, rowB = 0;
        int cntA = 0, cntB = 0;
        for (int i = 0; i < N; ++i) {
            int cnt0 = 0, cnt1 = 0;
            for (int j = 0; j < N; ++j) {
                if (value(board, row, i, j) == 1) {
                    nums[i] |= 1 << j;
                    ++cnt1;
                } else {
                    ++cnt0;
                }
            }
            
            if (abs(cnt0 - cnt1) > 1) 
                return -1;
            
            if (rowA == 0 || rowA == nums[i]) 
                rowA = nums[i], ++cntA;
            else if (rowB == 0 || rowB == nums[i]) 
                rowB = nums[i], ++cntB;
            else 
                return -1;
        }
        
        if (abs(cntA - cntB) > 1) 
            return -1;
        
        if (cntA > cntB) {
            int ans = 0;
            for (int i = 0; i < N; i += 2) 
                if (rowA != nums[i]) ++ans;
            return ans;
        } else if (cntA < cntB) {
            int ans = 0;
            for (int i = 0; i < N; i += 2) 
                if (rowB != nums[i]) ++ans;
            return ans;
        } else {
            int ansA = 0, ansB = 0;
            for (int i = 0; i < N; i += 2) {
                if (rowA != nums[i]) ++ansA;
                if (rowB != nums[i]) ++ansB;
            }
            return min(ansA, ansB);
        }
    }
    
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        
        vector<int> rows(N);
        int moves0 = check(board, rows, true);
        if (moves0 == -1) return -1;
        
        vector<int> cols(N);
        int moves1 = check(board, cols, false);
        if (moves1 == -1) return -1;
        
        return moves0 + moves1;
    }
};