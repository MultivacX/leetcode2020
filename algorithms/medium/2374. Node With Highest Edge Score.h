// 2374. Node With Highest Edge Score
// https://leetcode.com/problems/node-with-highest-edge-score/

class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        vector<int64_t> scores(edges.size());
        for (int i = 0; i < edges.size(); ++i)
            scores[edges[i]] += i;

        int res = -1;
        int64_t s = 0;
        for (int i = edges.size() - 1; i >= 0; --i)
            if (s <= scores[i])
                s = scores[i], res = i;
        return res;
    }
};