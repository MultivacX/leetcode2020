// 174. Dungeon Game

// Runtime: 4 ms, faster than 99.02% of C++ online submissions for Dungeon Game.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Dungeon Game.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int ROWS = dungeon.size();
        if (ROWS == 0) return 0;
        const int COLS = dungeon[0].size();
        if (COLS == 0) return 0;
        
        vector<int> dp(COLS, 0);
        dp[COLS - 1] = 1;
        for (int r = ROWS - 1; r >= 0; --r) {
            for (int c = COLS - 1; c >= 0; --c) {
                if (c == COLS - 1) {
                    // move down
                    dp[c] = hp(dungeon[r][c], dp[c]);
                    // cout << dp[c] << ", ";
                    continue;
                } 
                
                if (r == ROWS - 1) {
                    // move right
                    dp[c] = hp(dungeon[r][c], dp[c + 1]);
                    // cout << dp[c] << ", ";
                    continue;
                }
                
                dp[c] = min(hp(dungeon[r][c], dp[c]), hp(dungeon[r][c], dp[c + 1]));
                // cout << dp[c] << ", ";
            }
            // cout << " " << endl;
        }
        return dp[0] == 0 ? 1 : dp[0];
    }
    
    int hp(int curr, int next) {
        if (curr == 0) return max(1, next);
        else if (curr > next) return 0;
        else if (next == 0) return 1 - curr;
        else return next - curr;
    }
};