// 2144. Minimum Cost of Buying Candies With Discount
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// Runtime: 11 ms, faster than 25.45% of C++ online submissions for Minimum Cost of Buying Candies With Discount.
// Memory Usage: 10.9 MB, less than 34.75% of C++ online submissions for Minimum Cost of Buying Candies With Discount.

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.rbegin(), cost.rend());
        int i = 0, res = 0;
        const int n = cost.size();
        while (i < n)
        {
            res += cost[i++];
            if (i == n)
                break;

            res += cost[i++];

            ++i;
        }
        return res;
    }
};