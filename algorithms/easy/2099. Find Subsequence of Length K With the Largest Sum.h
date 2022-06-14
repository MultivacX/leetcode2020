// 2099. Find Subsequence of Length K With the Largest Sum
// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

// Runtime: 20 ms, faster than 12.12% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
// Memory Usage: 9.4 MB, less than 87.22% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        auto cmp = [&](int i, int j)
        {
            return nums[i] > nums[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < nums.size(); ++i)
        {
            q.push(i);
            if (q.size() > k)
                q.pop();
        }
        vector<int> res(k);
        int i = 0;
        while (!q.empty())
        {
            res[i++] = q.top();
            q.pop();
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < k; ++i)
            res[i] = nums[res[i]];
        return res;
    }
};