// 2208. Minimum Operations to Halve Array Sum
// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

// Runtime: 610 ms, faster than 17.13% of C++ online submissions for Minimum Operations to Halve Array Sum.
// Memory Usage: 89.3 MB, less than 62.76% of C++ online submissions for Minimum Operations to Halve Array Sum.

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> q;
        double sum = 0;
        for (int i : nums)
        {
            q.push(i);
            sum += i;
        }

        double half = sum * 0.5;
        int res = 0;
        while (sum > half)
        {
            double v = q.top();
            q.pop();
            q.push(v * 0.5);
            sum -= v * 0.5;
            ++res;
        }

        return res;
    }
};