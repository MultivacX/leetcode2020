// 2017. Grid Game
// https://leetcode.com/problems/grid-game/

// Runtime: 550 ms, faster than 9.48% of C++ online submissions for Grid Game.
// Memory Usage: 62.9 MB, less than 80.24% of C++ online submissions for Grid Game.

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long t = accumulate(grid[0].begin() + 1, grid[0].end(), (long long)0);
        long long b = 0;
        long long res = t;
        for (int i = 1; i < grid[0].size(); ++i)
        {
            t -= grid[0][i];
            b += grid[1][i - 1];
            // cout << t << ' ' << b << endl;
            res = min(res, max(t, b));
        }
        return res;
    }
};