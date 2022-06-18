// 2304. Minimum Path Cost in a Grid
// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

// Runtime: 483 ms, faster than 61.59% of C++ online submissions for Minimum Path Cost in a Grid.
// Memory Usage: 80.4 MB, less than 45.58% of C++ online submissions for Minimum Path Cost in a Grid.

class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<int> curCosts(grid[0]);
        for (int i = 1; i < m; ++i)
        {
            auto &preCosts = curCosts;
            vector<int> tmp(n, INT_MAX);

            for (int j = 0; j < n; ++j)
            {
                int pre = grid[i - 1][j];
                for (int k = 0; k < n; ++k)
                {
                    // cout << "  " << grid[i][k] << " + " << moveCost[pre][k] << " + " << preCosts[j] << endl;
                    tmp[k] = min(tmp[k], grid[i][k] + moveCost[pre][k] + preCosts[j]);
                }
            }

            // for (int j = 0; j < n; ++j) cout << tmp[j] << ", "; cout << endl;

            curCosts = tmp;
        }

        return *min_element(curCosts.begin(), curCosts.end());
    }
};