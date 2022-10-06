// 2240. Number of Ways to Buy Pens and Pencils
// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

// Runtime: 39 ms, faster than 12.13% of C++ online submissions for Number of Ways to Buy Pens and Pencils.
// Memory Usage: 5.9 MB, less than 72.46% of C++ online submissions for Number of Ways to Buy Pens and Pencils.

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        // 0 <= c1 * x + c2 * y <= t
        if (cost1 < cost2)
            swap(cost1, cost2);

        long long res = 0;
        for (long long x = 0; x <= total / cost1; ++x)
        {
            long long y = ((long long)total - cost1 * x) / cost2;
            res += 1 + y;
        }
        return res == 0 ? 1 : res;
    }
};