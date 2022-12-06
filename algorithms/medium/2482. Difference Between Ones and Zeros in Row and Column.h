// 2482. Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        const int m = grid.size(), n = grid[0].size();
        vector<int> m1(m), n1(n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                m1[i] += grid[i][j];
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                n1[j] += grid[i][j];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] = m1[i] + n1[j] - (m - m1[i]) - (n - n1[j]);
        return grid;
    }
};