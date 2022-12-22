// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long res = 0, tmp = 0;
        unordered_set<int> s;
        for (int i = 0, l = 0; i < nums.size(); ++i)
        {
            if (!s.insert(nums[i]).second)
            {
                while (nums[l] != nums[i])
                {
                    tmp -= nums[l];
                    s.erase(nums[l++]);
                }
                ++l;
            }
            else
            {
                tmp += nums[i];
            }

            while (s.size() > k)
            {
                tmp -= nums[l];
                s.erase(nums[l++]);
            }

            if (s.size() == k)
                res = max(res, tmp);
        }
        return res;
    }
};