// 2295. Replace Elements in an Array
// https://leetcode.com/problems/replace-elements-in-an-array/

// Runtime: 328 ms, faster than 99.82% of C++ online submissions for Replace Elements in an Array.
// Memory Usage: 110.8 MB, less than 99.47% of C++ online submissions for Replace Elements in an Array.

int m[1000001]; // {val, idx+1}
class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i + 1;

        for (const auto &o : operations)
        {
            int i = m[o[0]] - 1;
            m[o[0]] = 0;
            m[o[1]] = i + 1;
            nums[i] = o[1];
        }

        return nums;
    }
};