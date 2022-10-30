// 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/

// Runtime: 159 ms, faster than 98.62% of C++ online submissions for Maximum Matrix Sum.
// Memory Usage: 35.3 MB, less than 25.17% of C++ online submissions for Maximum Matrix Sum.

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long minp = INT_MAX;
        long long maxn = INT_MIN;
        int cntn = 0;
        long long res = 0;
        for (const auto &v : matrix)
            for (int i : v)
            {
                if (i > 0)
                {
                    minp = min(minp, (long long)i);
                    res += i;
                }
                else
                {
                    maxn = max(maxn, (long long)i);
                    res -= i;
                    ++cntn;
                }
            }

        if (cntn & 1)
        {
            // cout << res << ' ' << minp << ' ' << maxn << endl;
            if (minp < -maxn)
                res -= minp * 2;
            else
                res += maxn * 2;
        }

        return res;
    }
};