// 2120. Execution of All Suffix Instructions Staying in a Grid
// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

// Runtime: 96 ms, faster than 19.53% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.
// Memory Usage: 10.2 MB, less than 87.28% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.

class Solution
{
    int exec(int n, int i, int j, const string &s, int k)
    {
        if (k >= s.length())
            return 0;

        if (s[k] == 'L')
            --j;
        else if (s[k] == 'R')
            ++j;
        else if (s[k] == 'U')
            --i;
        else if (s[k] == 'D')
            ++i;

        ++k;

        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0;

        return 1 + exec(n, i, j, s, k);
    }

public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        const int m = s.length();
        vector<int> res(m);
        for (int k = 0; k < m; ++k)
        {
            res[k] = exec(n, startPos[0], startPos[1], s, k);
        }
        return res;
    }
};