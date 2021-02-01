// 1463. Cherry Pickup II
// https://leetcode.com/problems/cherry-pickup-ii/

// Runtime: 116 ms, faster than 34.65% of C++ online submissions for Cherry Pickup II.
// Memory Usage: 14.4 MB, less than 51.32% of C++ online submissions for Cherry Pickup II.
    
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int Y = grid.size();
        const int X = grid[0].size();
        vector<vector<vector<int>>> cherries(Y, vector<vector<int>>(X, vector<int>(X, -1)));
        function<int(int, int, int)> dp = [&](int y, int x1, int x2){
            if (y < 0 || y >= Y || x1 < 0 || x1 >= X || x2 < 0 || x2 >= X)
                return 0;
            if (cherries[y][x1][x2] != -1) return cherries[y][x1][x2];
            
            int ans = 0;
            for (int i = -1; i <= 1; ++i) 
                for (int j = -1; j <= 1; ++j) 
                    ans = max(ans, dp(y + 1, x1 + i, x2 + j));
            ans += grid[y][x1] + (x1 == x2 ? 0 : grid[y][x2]);
            cherries[y][x1][x2] = ans;
            return ans;
        };
        return dp(0, 0, X - 1);
    }
};