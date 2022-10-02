// 2410. Maximum Matching of Players With Trainers
// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

// Runtime: 398 ms, faster than 31.75% of C++ online submissions for Maximum Matching of Players With Trainers.
// Memory Usage: 76.6 MB, less than 48.40% of C++ online submissions for Maximum Matching of Players With Trainers.

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        const int m = players.size(), n = trainers.size();
        int res = 0, i = 0, j = 0;
        while (i < m && j < n)
        {
            if (players[i] <= trainers[j])
            {
                ++res;
                ++i;
            }
            ++j;
        }
        return res;
    }
};