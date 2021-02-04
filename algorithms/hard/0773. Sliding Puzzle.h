// 773. Sliding Puzzle
// https://leetcode.com/problems/sliding-puzzle/

// Runtime: 20 ms, faster than 47.79% of C++ online submissions for Sliding Puzzle.
// Memory Usage: 11.8 MB, less than 35.58% of C++ online submissions for Sliding Puzzle.
    
class Solution {
    int getNum(const vector<vector<int>>& board) {
        return board[0][0] * 100000 + 
               board[0][1] *  10000 + 
               board[0][2] *   1000 + 
               board[1][0] *    100 + 
               board[1][1] *     10 + 
               board[1][2];
    }
    
    void move(int num, unordered_set<int>& nxt, unordered_set<int>& visited) {
        vector<vector<int>> board{
            {num / 100000, num / 10000 % 10, num / 1000 % 10},
            {num / 100 % 10, num / 10 % 10, num % 10}
        };
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 0) continue;
                static const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
                for (const auto& d : directions) {
                    int ii = i + d[0], jj = j + d[1];
                    if (ii < 0 || ii > 1 || jj < 0 || jj > 2)
                        continue;
                    
                    swap(board[ii][jj], board[i][j]);
                    int val = getNum(board);
                    nxt.insert(val);
                    swap(board[ii][jj], board[i][j]);
                }
                return;
            }
        }
    }
    
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<int> p{getNum(board)};
        unordered_set<int> q{123450};
        unordered_set<int> visited;
        
        int moves = 0;
        while (!p.empty() && !q.empty()) {
            auto& cur = p.size() <= q.size() ? p : q;
            auto& sta = p.size() <= q.size() ? q : p;
            unordered_set<int> nxt;
            for (int num : cur) {
                if (sta.count(num)) return moves;
                if (!visited.insert(num).second) continue;
                move(num, nxt, visited);
            }
            swap(cur, nxt);
            ++moves;
        }
        return -1;
    }
};