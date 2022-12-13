// 2289. Steps to Make Array Non-decreasing

// TLE
class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int res = 0, n = nums.size();
        while (true)
        {
            int t = 0;
            for (int i = n - 1; i > 0; --i)
                if (nums[i] < nums[i - 1])
                    nums[i] = 0, ++t;
            if (t == 0)
                return res;
            ++res;

            int i = 0, j = 0;
            while (i < n && j < n)
            {
                if (nums[i])
                {
                    ++i;
                    continue;
                }
                j = i + 1;
                while (j < n && nums[j] == 0)
                    ++j;
                if (j < n)
                {
                    nums[i] = nums[j];
                    nums[j] = 0;
                }
            }
            n -= t;
        }
        return res;
    }
};