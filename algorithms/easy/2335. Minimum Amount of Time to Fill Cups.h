// 2335. Minimum Amount of Time to Fill Cups
// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

// Runtime: 3 ms, faster than 84.67% of C++ online submissions for Minimum Amount of Time to Fill Cups.
// Memory Usage: 11.7 MB, less than 59.83% of C++ online submissions for Minimum Amount of Time to Fill Cups.

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        priority_queue<int> q;
        for (int i : amount)
            if (i > 0)
                q.push(i);

        int res = 0;
        while (!q.empty())
        {
            int _max = q.top();
            if (q.size() <= 2)
            {
                return res + _max;
            }
            else
            {
                q.pop();
                int _mid = q.top();
                q.pop();

                if (--_max)
                    q.push(_max);
                if (--_mid)
                    q.push(_mid);
                res += 1;
            }
        }
        return res;
    }
};