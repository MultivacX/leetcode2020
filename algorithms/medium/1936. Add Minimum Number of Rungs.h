// 1936. Add Minimum Number of Rungs
// https://leetcode.com/problems/add-minimum-number-of-rungs/

// Runtime: 107 ms, faster than 97.18% of C++ online submissions for Add Minimum Number of Rungs.
// Memory Usage: 54 MB, less than 93.73% of C++ online submissions for Add Minimum Number of Rungs.

class Solution
{
public:
    int addRungs(vector<int> &rungs, int dist)
    {
        int h = 0, res = 0;
        for (int r : rungs)
        {
            int d = r - h;
            h = r;
            if (d <= dist)
                continue;
            int k = d / dist;
            if (d == k * dist)
                res += k - 1;
            else
                res += k;
        }
        return res;
    }
};