// 2225. Find Players With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// Runtime: 1003 ms, faster than 56.23% of C++ online submissions for Find Players With Zero or One Losses.
// Memory Usage: 166.1 MB, less than 77.97% of C++ online submissions for Find Players With Zero or One Losses.

class Solution
{
public:
    vector<vector<int> > findWinners(vector<vector<int> > &matches)
    {
        map<int, int> cnt;
        for (const auto &m : matches)
        {
            cnt[m[0]];
            ++cnt[m[1]];
        }

        vector<int> a, b;
        for (const auto it : cnt)
        {
            if (it.second == 0)
            {
                a.push_back(it.first);
            }
            if (it.second == 1)
            {
                b.push_back(it.first);
            }
        }
        return {a, b};
    }
};