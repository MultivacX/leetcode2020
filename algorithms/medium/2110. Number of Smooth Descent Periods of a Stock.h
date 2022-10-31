// 2110. Number of Smooth Descent Periods of a Stock
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

// Runtime: 435 ms, faster than 14.32% of C++ online submissions for Number of Smooth Descent Periods of a Stock.
// Memory Usage: 93.1 MB, less than 74.81% of C++ online submissions for Number of Smooth Descent Periods of a Stock.

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long res = 1;
        const int n = prices.size();
        for (int i = 1, k = 1; i < n; ++i)
        {
            if (prices[i - 1] - 1 == prices[i])
            {
                ++k;
            }
            else
            {
                k = 1;
            }
            res += k;
        }
        return res;
    }
};