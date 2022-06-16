// 2294. Partition Array Such That Maximum Difference Is K
// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

// Runtime: 209 ms, faster than 93.13% of C++ online submissions for Partition Array Such That Maximum Difference Is K.
// Memory Usage: 83.1 MB, less than 52.69% of C++ online submissions for Partition Array Such That Maximum Difference Is K.

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int res = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0, s = 0; i < nums.size(); ++i)
        {
            if (nums[i] - nums[s] > k)
            {
                ++res;
                s = i;
            }
        }
        return res;
    }
};