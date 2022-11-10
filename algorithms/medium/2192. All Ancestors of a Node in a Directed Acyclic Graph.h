// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

// Runtime: 285 ms, faster than 80.70% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.
// Memory Usage: 59.6 MB, less than 97.69% of C++ online submissions for All Ancestors of a Node in a Directed Acyclic Graph.

class Solution
{
    void dfs(vector<vector<int>> &g, vector<vector<int>> &res, int a, int i)
    {
        for (int j : g[i])
        {
            if (!res[j].empty() && res[j].back() == a)
                continue;
            res[j].push_back(a);
            dfs(g, res, a, j);
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> res(n), g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]);
        // for (int i = 0; i < n ; ++i) {
        //     cout << i << ':' << ' ';
        //     for (int j : g[i])
        //         cout << j << ' ';
        //     cout << endl;
        // }
        for (int i = 0; i < n; ++i)
            dfs(g, res, i, i);
        return res;
    }
};