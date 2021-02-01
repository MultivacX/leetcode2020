// 1222. Queens That Can Attack the King
// https://leetcode.com/problems/queens-that-can-attack-the-king/

// Runtime: 8 ms, faster than 73.13% of C++ online submissions for Queens That Can Attack the King.
// Memory Usage: 11.3 MB, less than 21.57% of C++ online submissions for Queens That Can Attack the King.

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        static const vector<vector<int>> offsets{
            {0, 1}, {0, -1}, {1, -1}, {1, 1},                            
            {1, 0}, {-1, 0}, {-1, 1}, {-1, -1},                            
        };
        // {distance, index}
        vector<vector<int>> Q(8, vector<int>{INT_MAX, -1}); 
        for (int q = 0; q < queens.size(); ++q) {
            int x = king[0] - queens[q][0];
            int y = king[1] - queens[q][1];
            // printf("[%d,%d]->[%d,%d]: ", king[0], king[1], queens[q][0], queens[q][1]);
            if (!(x == 0 || y == 0 || abs(x) == abs(y))) continue;
            int distance = abs(x) + abs(y);
            if (x != 0) x /= abs(x);
            if (y != 0) y /= abs(y);
            for (int i = 0; i < 8; ++i) {
                if (offsets[i][0] == x && offsets[i][1] == y) {
                    if (distance < Q[i][0]) {
                        Q[i][0] = distance;
                        Q[i][1] = q;
                    }
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < 8; ++i) 
            if (Q[i][1] >= 0) ans.push_back(queens[Q[i][1]]);
        return ans;
    }
};