// 2348. Number of Zero-Filled Subarrays
// https://leetcode.com/problems/number-of-zero-filled-subarrays/

// Runtime: 478 ms, faster than 8.09% of C++ online submissions for Number of Zero-Filled Subarrays.
// Memory Usage: 107.6 MB, less than 11.39% of C++ online submissions for Number of Zero-Filled Subarrays.

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0, k = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] == 0)
                res += ++k;
            else
                k = 0;
        return res;
    }
};