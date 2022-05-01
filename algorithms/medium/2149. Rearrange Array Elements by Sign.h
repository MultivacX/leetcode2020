// 2149. Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Runtime: 249 ms, faster than 73.62% of C++ online submissions for Rearrange Array Elements by Sign.
// Memory Usage: 124 MB, less than 70.15% of C++ online submissions for Rearrange Array Elements by Sign.

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> res(nums);
        int i = 0, j = 1, k = 0;
        while (k < n)
        {
            if (nums[k] > 0)
            {
                res[i] = nums[k];
                i += 2;
            }
            else
            {
                res[j] = nums[k];
                j += 2;
            }
            ++k;
        }
        return res;
    }
};