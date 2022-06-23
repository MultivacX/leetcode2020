// 2190. Most Frequent Number Following Key In an Array
// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

// Runtime: 11 ms, faster than 85.25% of C++ online submissions for Most Frequent Number Following Key In an Array.
// Memory Usage: 13.1 MB, less than 6.50% of C++ online submissions for Most Frequent Number Following Key In an Array.

class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        vector<int> m(1001);
        const int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
            if (nums[i] == key)
                ++m[nums[i + 1]];

        int res = 0, cnt = 0;
        for (int i = 1; i <= 1000; ++i)
            if (cnt < m[i])
                res = i, cnt = m[i];
        return res;
    }
};