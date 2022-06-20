// 1962. Remove Stones to Minimize the Total
// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

// Runtime: 800 ms, faster than 53.70% of C++ online submissions for Remove Stones to Minimize the Total.
// Memory Usage: 105.1 MB, less than 30.22% of C++ online submissions for Remove Stones to Minimize the Total.

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> q;
        for (int i : piles)
            q.push(i);
        while (k--)
        {
            int i = q.top();
            q.pop();
            q.push(i - i / 2);
        }

        int res = 0;
        while (!q.empty())
        {
            res += q.top();
            q.pop();
        }
        return res;
    }
};