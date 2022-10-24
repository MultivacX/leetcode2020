// 2049. Count Nodes With the Highest Score
// https://leetcode.com/problems/count-nodes-with-the-highest-score/

// Runtime: 393 ms, faster than 84.38% of C++ online submissions for Count Nodes With the Highest Score.
// Memory Usage: 79.2 MB, less than 97.92% of C++ online submissions for Count Nodes With the Highest Score.

class Solution
{
    int count(int i, vector<array<int, 4>> &nodes)
    {
        int l = nodes[i][0];
        nodes[i][1] = l == -1 ? 0 : (1 + count(l, nodes));

        int r = nodes[i][2];
        nodes[i][3] = r == -1 ? 0 : (1 + count(r, nodes));

        return nodes[i][1] + nodes[i][3];
    }

public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        const int n = parents.size();
        vector<array<int, 4>> nodes(n, array<int, 4>{-1, 0, -1, 0});
        for (int i = 1; i < n; ++i)
        {
            int p = parents[i];
            if (nodes[p][0] == -1)
                nodes[p][0] = i;
            else
                nodes[p][2] = i;
        }
        count(0, nodes);

        uint64_t k = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            uint64_t subCnt = 1 + nodes[i][1] + nodes[i][3];
            uint64_t v = max((uint64_t)1, (uint64_t)n - subCnt) * max(1, nodes[i][1]) * max(1, nodes[i][3]);
            if (k == v)
            {
                ++res;
            }
            else if (k < v)
            {
                k = v;
                res = 1;
            }
        }
        return res;
    }
};