// 2279. Maximum Bags With Full Capacity of Rocks
// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

// Runtime: 449 ms, faster than 19.59% of C++ online submissions for Maximum Bags With Full Capacity of Rocks.
// Memory Usage: 84.6 MB, less than 88.48% of C++ online submissions for Maximum Bags With Full Capacity of Rocks.

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        for (int i = 0; i < rocks.size(); ++i)
        {
            rocks[i] = max(0, capacity[i] - rocks[i]);
        }
        sort(rocks.begin(), rocks.end());

        int res = 0;
        for (int i = 0; i < rocks.size() && additionalRocks > 0; ++i)
        {
            additionalRocks -= rocks[i];
            if (additionalRocks >= 0)
                ++res;
        }
        return res;
    }
};