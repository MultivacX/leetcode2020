// 2161. Partition Array According to Given Pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

// Runtime: 258 ms, faster than 59.67% of C++ online submissions for Partition Array According to Given Pivot.
// Memory Usage: 123.4 MB, less than 84.59% of C++ online submissions for Partition Array According to Given Pivot.

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        const int n = nums.size();
        vector<int> res(n, pivot);
        int i = 0, j = n - 1, l = 0, r = n - 1;
        while (i < n)
        {
            if (nums[i] < pivot)
                res[l++] = nums[i];
            ++i;
        }
        while (j >= 0)
        {
            if (nums[j] > pivot)
                res[r--] = nums[j];
            --j;
        }
        return res;
    }
};