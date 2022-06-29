// 2133. Check if Every Row and Column Contains All Numbers
// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

// Runtime: 127 ms, faster than 96.13% of C++ online submissions for Check if Every Row and Column Contains All Numbers.
// Memory Usage: 35.1 MB, less than 82.34% of C++ online submissions for Check if Every Row and Column Contains All Numbers.

class Solution
{
public:
    bool checkValid(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        vector<int> m(n);
        for (int i = 0, k = 0; i < n; ++i)
        {
            ++k;
            for (int j = 0; j < n; ++j)
                if (++m[matrix[i][j] - 1] != k)
                    return false;

            ++k;
            for (int j = 0; j < n; ++j)
                if (++m[matrix[j][i] - 1] != k)
                    return false;
        }
        return true;
    }
};