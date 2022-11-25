// 2070. Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query/

// Runtime: 383 ms, faster than 97.35% of C++ online submissions for Most Beautiful Item for Each Query.
// Memory Usage: 88.3 MB, less than 93.18% of C++ online submissions for Most Beautiful Item for Each Query.

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());

        const int m = items.size(), n = queries.size();
        vector<int> res(n), qs(n);
        iota(qs.begin(), qs.end(), 0);
        sort(qs.begin(), qs.end(), [&](int i, int j)
             { return queries[i] < queries[j]; });

        int j = 0, beauty = 0;
        for (int i : qs)
        {
            while (j < m && items[j][0] <= queries[i])
            {
                beauty = max(beauty, items[j++][1]);
            }
            res[i] = beauty;
        }

        return res;
    }
};