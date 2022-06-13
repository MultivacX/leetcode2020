// 2044. Count Number of Maximum Bitwise-OR Subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

// Runtime: 20 ms, faster than 86.07% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.
// Memory Usage: 8.4 MB, less than 82.24% of C++ online submissions for Count Number of Maximum Bitwise-OR Subsets.

class Solution
{
    int res = 0;
    int m = 0;

    void count(vector<int> &nums, int i, int v)
    {
        if (i >= nums.size())
        {
            if (m == v)
                ++res;
            return;
        }

        count(nums, i + 1, v);
        count(nums, i + 1, v | nums[i]);
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            m |= nums[i];
        // cout << m << endl;
        count(nums, 0, 0);
        return res;
    }
};