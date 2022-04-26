// 2221. Find Triangular Sum of an Array
// https://leetcode.com/problems/find-triangular-sum-of-an-array/

// Runtime: 320 ms, faster than 72.40% of C++ online submissions for Find Triangular Sum of an Array.
// Memory Usage: 18.7 MB, less than 72.78% of C++ online submissions for Find Triangular Sum of an Array.

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        while (nums.size() > 1)
        {
            for (int i = 0; i + 1 < nums.size(); ++i)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};