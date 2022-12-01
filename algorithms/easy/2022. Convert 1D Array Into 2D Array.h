// 2022. Convert 1D Array Into 2D Array
// https://leetcode.com/problems/convert-1d-array-into-2d-array/

// Runtime: 337 ms, faster than 19.45% of C++ online submissions for Convert 1D Array Into 2D Array.
// Memory Usage: 85.4 MB, less than 67.19% of C++ online submissions for Convert 1D Array Into 2D Array.

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int l = original.size();
        if (l != m * n)
            return {};

        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0, k = 0; i < m; ++i)
            for (int j = 0; j < n; ++j, ++k)
                res[i][j] = original[k];
        return res;
    }
};