// 310. Minimum Height Trees

// Runtime: 200 ms, faster than 5.92% of C++ online submissions for Minimum Height Trees.
// Memory Usage: 33.8 MB, less than 7.14% of C++ online submissions for Minimum Height Trees.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        // {root, {child, height}}
        vector<unordered_map<int, int>> m(n, unordered_map<int, int>());
        int height = n + 1;
        deque<int> q;
        q.push_back(0);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop_front();
                if (visited[i]) continue;
                visited[i] = true;
                f(g, m, i, -1);
                int h = 0;
                for (int j : g[i]) {
                    h = max(h, m[i][j]);
                    if (visited[j]) continue;
                    q.push_back(j);
                }
                height = min(height, h);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int h = 0;
            for (int j : g[i]) h = max(h, m[i][j]);
            if (h == height) ans.push_back(i);
        }
        return ans;
    }
    
    void f(vector<vector<int>>& g, vector<unordered_map<int, int>>& m, int i, int pre) {
        if (g[i].size() == m[i].size()) return;
        
        for (int j : g[i]) {
            if (j == pre) continue;
            if (m[i].count(j)) continue;
            f(g, m, j, i);
            m[i][j] = 1 + depth(g, m, j, i);
        }
    }
    
    int depth(vector<vector<int>>& g, vector<unordered_map<int, int>>& m, int i, int exclusive) {
        int d = 0;
        for (int j : g[i]) {
            if (j == exclusive) continue;
            d = max(d, m[i][j]);
        }
        return d;
    }
};