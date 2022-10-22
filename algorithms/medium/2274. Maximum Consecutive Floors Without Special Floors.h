// 2274. Maximum Consecutive Floors Without Special Floors
// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

// Runtime: 507 ms, faster than 7.42% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.
// Memory Usage: 58.1 MB, less than 6.36% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int res = max(special.front() - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i)
            res = max(res, special[i] - special[i - 1] - 1);
        return res;
    }
};