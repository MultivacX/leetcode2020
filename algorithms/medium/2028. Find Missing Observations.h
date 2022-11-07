// 2028. Find Missing Observations
// https://leetcode.com/problems/find-missing-observations/

// Runtime: 420 ms, faster than 9.61% of C++ online submissions for Find Missing Observations.
// Memory Usage: 113.5 MB, less than 90.58% of C++ online submissions for Find Missing Observations.

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int sum = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (sum < n || sum > n * 6)
            return {};

        vector<int> res(n, 1);
        int i = 0;
        sum -= n;
        while (sum)
        {
            int v = min(5, sum);
            res[i++] += v;
            sum -= v;
        }
        return res;
    }
};