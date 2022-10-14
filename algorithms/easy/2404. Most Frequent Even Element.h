// 2404. Most Frequent Even Element
// https://leetcode.com/problems/most-frequent-even-element/

// Runtime: 181 ms, faster than 55.24% of C++ online submissions for Most Frequent Even Element.
// Memory Usage: 38 MB, less than 89.62% of C++ online submissions for Most Frequent Even Element.

class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int k = 0;
        for (int i : nums)
        {
            if (i & 1)
                continue;
            if (++m[i] > k)
                k = m[i];
        }

        int res = INT_MAX;
        for (auto [num, cnt] : m)
        {
            if (cnt != k)
                continue;
            res = min(res, num);
        }
        return res == INT_MAX ? -1 : res;
    }
};