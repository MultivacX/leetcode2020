// 2492. Minimum Score of a Path Between Two Cities
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

// Runtime: 448 ms, faster than 95.24% of C++ online submissions for Minimum Score of a Path Between Two Cities.
// Memory Usage: 127.6 MB, less than 76.19% of C++ online submissions for Minimum Score of a Path Between Two Cities.

class Solution
{
    int res = 10000;

    void dfs(vector<vector<pair<int, int>>> &g, vector<bool> &visited, int i)
    {
        if (visited[i])
            return;
        visited[i] = true;

        for (auto &p : g[i])
        {
            int b = p.first;
            int d = p.second;
            res = min(res, d);
            dfs(g, visited, b);
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto &r : roads)
        {
            int a = r[0];
            int b = r[1];
            int d = r[2];
            g[a].push_back({b, d});
            g[b].push_back({a, d});
        }

        vector<bool> visited(n + 1);
        dfs(g, visited, 1);
        return res;
    }
};