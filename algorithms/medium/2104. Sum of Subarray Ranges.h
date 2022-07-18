// 2104. Sum of Subarray Ranges
// https://leetcode.com/problems/sum-of-subarray-ranges/

// Runtime: 22 ms, faster than 83.50% of C++ online submissions for Sum of Subarray Ranges.
// Memory Usage: 10.5 MB, less than 70.64% of C++ online submissions for Sum of Subarray Ranges.

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        const int n = nums.size();
        long long res = 0;
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; ++i)
        {
            while (s.top() != -1 && nums[s.top()] > nums[i])
            {
                // k < j < i
                int j = s.top();
                s.pop();
                int k = s.top();
                res -= (long long)nums[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        while (s.top() != -1)
        {
            // k < j < n
            int j = s.top();
            s.pop();
            int k = s.top();
            res -= (long long)nums[j] * (n - j) * (j - k);
        }

        for (int i = 0; i < n; ++i)
        {
            while (s.top() != -1 && nums[s.top()] < nums[i])
            {
                // k < j < i
                int j = s.top();
                s.pop();
                int k = s.top();
                res += (long long)nums[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        while (s.top() != -1)
        {
            // k < j < n
            int j = s.top();
            s.pop();
            int k = s.top();
            res += (long long)nums[j] * (n - j) * (j - k);
        }

        return res;
    }
};