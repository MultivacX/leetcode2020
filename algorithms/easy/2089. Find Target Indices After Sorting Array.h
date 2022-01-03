// 2089. Find Target Indices After Sorting Array
// https://leetcode.com/problems/find-target-indices-after-sorting-array/

// Runtime: 15 ms, faster than 5.78% of C++ online submissions for Find Target Indices After Sorting Array.
// Memory Usage: 11.7 MB, less than 12.04% of C++ online submissions for Find Target Indices After Sorting Array.

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int less = 0, k = 0;
        for (int i : nums)
        {
            if (i < target)
            {
                ++less;
            }
            else if (i == target)
            {
                ++k;
            }
        }

        if (k == 0)
        {
            return {};
        }

        vector<int> ans(k);
        int i = 0;
        while (k--)
        {
            ans[i++] = less++;
        }
        return ans;
    }
};