// 2260. Minimum Consecutive Cards to Pick Up
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

// Runtime: 923 ms, faster than 24.76% of C++ online submissions for Minimum Consecutive Cards to Pick Up.
// Memory Usage: 115.2 MB, less than 48.42% of C++ online submissions for Minimum Consecutive Cards to Pick Up.

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int res = INT_MAX;
        unordered_map<int, int> m;
        for (int i = 0; i < cards.size(); ++i)
        {
            auto it = m.find(cards[i]);
            if (it != m.end())
                res = min(res, i - it->second + 1);
            m[cards[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};