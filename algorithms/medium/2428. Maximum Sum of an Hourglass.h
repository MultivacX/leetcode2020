// 2428. Maximum Sum of an Hourglass
// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

// Runtime: 116 ms, faster than 16.49% of C++ online submissions for Maximum Sum of an Hourglass.
// Memory Usage: 13.1 MB, less than 99.56% of C++ online submissions for Maximum Sum of an Hourglass.

class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                grid[i][j] += grid[i][j - 1];
            }
        }

        int res = 0;
        for (int i = 0; i + 2 < m; ++i)
        {
            for (int j = 2; j < n; ++j)
            {
                int sum = grid[i][j] - (j >= 3 ? grid[i][j - 3] : 0);
                sum += grid[i + 1][j - 1] - grid[i + 1][j - 2];
                sum += grid[i + 2][j] - (j >= 3 ? grid[i + 2][j - 3] : 0);
                res = max(res, sum);
            }
        }
        return res;
    }
};