// 741. Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/

// Runtime: 68 ms, faster than 64.99% of C++ online submissions for Cherry Pickup.
// Memory Usage: 22.4 MB, less than 49.55% of C++ online submissions for Cherry Pickup.

class Solution {
    int pickup(int r0, int c0, int r1, const vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // steps = r0 + c0 = r1 + c1
        int c1 = r0 + c0 - r1;
        if (r0 < 0 || c0 < 0 || r1 < 0 || c1 < 0) return INT_MIN + 1000;
        if (grid[r0][c0] == -1 || grid[r1][c1] == -1) return INT_MIN + 1000;
        
        if (dp[r0][c0][r1] != INT_MIN) return dp[r0][c0][r1];
        if (r0 == 0 && c0 == 0) return dp[r0][c0][r1] = grid[r0][c0];
        
        int ans = grid[r0][c0] + (r0 != r1 ? grid[r1][c1] : 0);
        ans += max(max(pickup(r0 - 1, c0, r1, grid, dp), pickup(r0, c0 - 1, r1, grid, dp)),
                   max(pickup(r0 - 1, c0, r1 - 1, grid, dp), pickup(r0, c0 - 1, r1 - 1, grid, dp)));
        // ans < 0 : dead end
        // printf("%d,%d  %d,%d   %d\n", r0, c0, r1, c1, ans);
        return dp[r0][c0][r1] = ans;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        pickup(N - 1, N - 1, N - 1, grid, dp);
        return max(0, dp[N - 1][N - 1][N - 1]);
    }
};

// Wrong Answer
// 55 / 56 test cases passed.
/*class Solution {
    int pickup(int r0, int c0, int r1, const vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // steps = r0 + c0 = r1 + c1
        int c1 = r0 + c0 - r1;
        if (r0 < 0 || c0 < 0 || r1 < 0 || c1 < 0) return 0;
        if (grid[r0][c0] == -1 || grid[r1][c1] == -1) return 0;
        
        if (dp[r0][c0][r1] >= 0) return dp[r0][c0][r1];
        
        int ans = grid[r0][c0] + (r0 != r1 ? grid[r1][c1] : 0);
        ans += max(max(pickup(r0 - 1, c0, r1, grid, dp), pickup(r0, c0 - 1, r1, grid, dp)),
                   max(pickup(r0 - 1, c0, r1 - 1, grid, dp), pickup(r0, c0 - 1, r1 - 1, grid, dp)));
        dp[r0][c0][r1] = ans;
        // printf("%d,%d  %d,%d   %d\n", r0, c0, r1, c1, ans);
        return dp[r0][c0][r1];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
        pickup(N - 1, N - 1, N - 1, grid, dp);
        return dp[0][0][0] < 0 ? 0 : dp[N - 1][N - 1][N - 1];
    }
};*/