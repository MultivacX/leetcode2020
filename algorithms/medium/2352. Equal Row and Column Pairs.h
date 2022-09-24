// 2352. Equal Row and Column Pairs
// https://leetcode.com/problems/equal-row-and-column-pairs/

// Runtime: 927 ms, faster than 10.32% of C++ online submissions for Equal Row and Column Pairs.
// Memory Usage: 23.7 MB, less than 73.91% of C++ online submissions for Equal Row and Column Pairs.

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        vector<int> rowSums(n), colSums(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                rowSums[i] += grid[i][j],
                    colSums[i] += grid[j][i];

        int res = 0;
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (rowSums[r] != colSums[c])
                    continue;

                bool b = true;
                for (int k = 0; k < n && b; ++k)
                    b = grid[r][k] == grid[k][c];
                if (b)
                    ++res;
            }
        }
        return res;
    }
};