// 2285. Maximum Total Importance of Roads
// https://leetcode.com/problems/maximum-total-importance-of-roads/

// Runtime: 639 ms, faster than 62.03% of C++ online submissions for Maximum Total Importance of Roads.
// Memory Usage: 112.7 MB, less than 90.82% of C++ online submissions for Maximum Total Importance of Roads.

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degrees(n);
        for (auto &r : roads)
        {
            ++degrees[r[0]];
            ++degrees[r[1]];
        }
        sort(begin(degrees), end(degrees));

        long long res = 0;
        for (long long i = 0; i < n; ++i)
            res += (i + 1) * degrees[i];
        return res;
    }
};