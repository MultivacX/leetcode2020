// 2016. Maximum Difference Between Increasing Elements
// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

// Runtime: 3 ms, faster than 88.92% of C++ online submissions for Maximum Difference Between Increasing Elements.
// Memory Usage: 8.4 MB, less than 39.18% of C++ online submissions for Maximum Difference Between Increasing Elements.

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        const int n = nums.size();
        int res = -1;
        for (int i = 1, l = 0; i < n; ++i)
        {
            res = max(res, nums[i] - nums[l]);
            if (nums[l] > nums[i])
                l = i;
        }
        return res == 0 ? -1 : res;
    }
};