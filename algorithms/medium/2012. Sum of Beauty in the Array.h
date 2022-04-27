// 2012. Sum of Beauty in the Array
// https://leetcode.com/problems/sum-of-beauty-in-the-array/

// Runtime: 263 ms, faster than 18.43% of C++ online submissions for Sum of Beauty in the Array.
// Memory Usage: 88.6 MB, less than 30.85% of C++ online submissions for Sum of Beauty in the Array.

class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> left_max(n, nums[0]);
        vector<int> right_min(n, nums[n - 1]);

        for (int i = 1; i < n; ++i)
        {
            left_max[i] = max(left_max[i - 1], nums[i - 1]);

            int j = n - i - 1;
            right_min[j] = min(right_min[j + 1], nums[j + 1]);
        }

        int ans = 0;
        int i = 1;
        while (i < n - 1)
        {
            if (left_max[i] < nums[i] && nums[i] < right_min[i])
                ans += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                ans += 1;
            ++i;
        }
        return ans;
    }
};