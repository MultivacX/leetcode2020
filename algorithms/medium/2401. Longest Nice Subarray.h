// 2401. Longest Nice Subarray
// https://leetcode.com/problems/longest-nice-subarray/

// Runtime: 709 ms, faster than 17.14% of C++ online submissions for Longest Nice Subarray.
// Memory Usage: 57.2 MB, less than 18.53% of C++ online submissions for Longest Nice Subarray.

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 0;
        int cnt[31] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0, left = 0; i < nums.size(); ++i)
        {
            bool nice = true;
            for (int j = 0; j < 31; ++j)
            {
                cnt[j] += (nums[i] >> j) & 1;
                if (cnt[j] > 1)
                    nice = false;
            }
            while (!nice)
            {
                bool tmp = true;
                for (int j = 0; j < 31; ++j)
                {
                    cnt[j] -= (nums[left] >> j) & 1;
                    if (cnt[j] > 1)
                        tmp = false;
                }
                ++left;
                nice = tmp;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};