// 2368. Reachable Nodes With Restrictions
// https://leetcode.com/problems/reachable-nodes-with-restrictions/

// Runtime: 831 ms, faster than 67.50% of C++ online submissions for Reachable Nodes With Restrictions.
// Memory Usage: 141.5 MB, less than 98.56% of C++ online submissions for Reachable Nodes With Restrictions.

class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<int> nodes(n); // visited:1, restricted:-1
        for (int r : restricted)
            nodes[r] = -1;

        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            if (nodes[e[0]] < 0 || nodes[e[1]] < 0)
                continue;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 1;
        nodes[0] = 1;
        vector<int> bfs{0};
        while (!bfs.empty())
        {
            vector<int> tmp;
            for (int i : bfs)
            {
                for (int j : adj[i])
                {
                    if (nodes[j])
                        continue;
                    ++res;
                    nodes[j] = 1;
                    tmp.push_back(j);
                }
            }
            bfs = tmp;
        }
        return res;
    }
};