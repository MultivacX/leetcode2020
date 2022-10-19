// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

// Runtime: 59 ms, faster than 58.21% of C++ online submissions for Largest Positive Integer That Exists With Its Negative.
// Memory Usage: 19.8 MB, less than 73.07% of C++ online submissions for Largest Positive Integer That Exists With Its Negative.

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        bitset<1001> a, b;
        int res = -1;
        for (int i : nums)
        {
            if (i > 0)
            {
                a[i] = true;
            }
            else
            {
                i = -i;
                b[i] = true;
            }

            if (a[i] && b[i] && i > res)
                res = i;
        }
        return res;
    }
};