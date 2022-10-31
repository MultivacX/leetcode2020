// 2090. K Radius Subarray Averages
// https://leetcode.com/problems/k-radius-subarray-averages/

// Runtime: 215 ms, faster than 98.93% of C++ online submissions for K Radius Subarray Averages.
// Memory Usage: 130 MB, less than 67.32% of C++ online submissions for K Radius Subarray Averages.

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> res(n, -1);
        if (n <= k)
            return res;
        long long sum = 0;
        for (int i = 0, j = -1; i < n; ++i)
        {
            sum += nums[i];
            int len = i - j;
            if (len == k * 2 + 1)
            {
                res[i - k] = sum / len;
                ++j;
                sum -= nums[j];
            }
        }
        return res;
    }
};