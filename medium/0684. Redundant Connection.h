// 684. Redundant Connection

// Runtime: 8 ms, faster than 78.07% of C++ online submissions for Redundant Connection.
// Memory Usage: 11.1 MB, less than 35.29% of C++ online submissions for Redundant Connection.

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        deque<int> q;
        for (auto& it : m) if (it.second.size() == 1) q.push_back(it.first);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop_front();
                int v = *m[u].begin();
                m.erase(u);
                m[v].erase(u);
                if (m[v].empty()) m.erase(v);
                else if (m[v].size() == 1) q.push_back(v);
            }
        }
        for (int i = edges.size() - 1; i >= 0; --i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (m.count(u) && m[u].count(v)) return edges[i];
            if (m.count(v) && m[v].count(u)) return edges[i];
        }
        return {};
    }
};