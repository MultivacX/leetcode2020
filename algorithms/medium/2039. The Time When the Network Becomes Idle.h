// 2039. The Time When the Network Becomes Idle
// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

// Runtime: 1382 ms, faster than 45.63% of C++ online submissions for The Time When the Network Becomes Idle.
// Memory Usage: 188.9 MB, less than 62.74% of C++ online submissions for The Time When the Network Becomes Idle.

class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        const int n = patience.size();
        vector<vector<int>> g(n);
        for (const auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> times(n);
        queue<int> q;
        q.push(0);
        int size = 1, t = 0;
        while (size > 0)
        {
            t += 1;
            for (int i = 0; i < size; ++i)
            {
                int cur = q.front();
                q.pop();

                for (int nxt : g[cur])
                {
                    if (times[nxt] > 0)
                        continue;
                    times[nxt] = t;
                    q.push(nxt);
                }
            }

            size = q.size();
        }

        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            int t = times[i] * 2;
            int p = patience[i];
            if (p >= t)
            {
                res = max(res, t + 1);
            }
            else
            {
                int k = t / p;
                int last = t == p * k ? t - p : p * k;
                res = max(res, last + t + 1);
            }
        }
        return res;
    }
};