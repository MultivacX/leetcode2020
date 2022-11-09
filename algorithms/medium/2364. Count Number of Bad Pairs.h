// 2364. Count Number of Bad Pairs
// https://leetcode.com/problems/count-number-of-bad-pairs/

// Runtime: 345 ms, faster than 77.62% of C++ online submissions for Count Number of Bad Pairs.
// Memory Usage: 88.6 MB, less than 19.91% of C++ online submissions for Count Number of Bad Pairs.

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<long long, long long> m;
        const auto n = nums.size();
        for (long long i = 0; i < n; ++i)
            ++m[i - nums[i]];
        long long res = 0, k = n;
        for (long long i = 0; i < n; ++i)
        {
            auto x = m[i - nums[i]];
            if (x == 0)
                continue;
            auto y = k - x;
            res += x * y;
            k -= x;
            m[i - nums[i]] = 0;
        }
        return res;
    }
};