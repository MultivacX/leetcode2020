// 2191. Sort the Jumbled Numbers
// https://leetcode.com/problems/sort-the-jumbled-numbers/

// Runtime: 720 ms, faster than 63.23% of C++ online submissions for Sort the Jumbled Numbers.
// Memory Usage: 76.5 MB, less than 95.82% of C++ online submissions for Sort the Jumbled Numbers.

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<array<int, 2>> tmp(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            tmp[i][0] = 0;
            tmp[i][1] = nums[i];

            auto str = to_string(nums[i]);
            for (char c : str)
            {
                int v = mapping[c - '0'];
                tmp[i][0] = tmp[i][0] * 10 + v;
            }
        }
        sort(tmp.begin(), tmp.end(), [](array<int, 2> &a, array<int, 2> &b)
             { return a[0] < b[0]; });

        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] = tmp[i][1];
        }
        return nums;
    }
};