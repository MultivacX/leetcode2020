// 2358. Maximum Number of Groups Entering a Competition
// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

// Runtime: 238 ms, faster than 8.14% of C++ online submissions for Maximum Number of Groups Entering a Competition.
// Memory Usage: 56.6 MB, less than 58.17% of C++ online submissions for Maximum Number of Groups Entering a Competition.

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        return (sqrt(1 + 8 * grades.size()) - 1) / 2;
    }
};