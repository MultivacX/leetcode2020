// 2239. Find Closest Number to Zero
// https://leetcode.com/problems/find-closest-number-to-zero/

// Runtime: 36 ms, faster than 50.54% of C++ online submissions for Find Closest Number to Zero.
// Memory Usage: 19.5 MB, less than 91.96% of C++ online submissions for Find Closest Number to Zero.

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int d = INT_MAX;
        int k = INT_MIN;
        for (int i : nums)
        {
            if (i == 0)
                return 0;

            if (d > abs(i) || d == i)
            {
                d = abs(i);
                k = i;
            }
        }
        return k;
    }
};