// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/

// Runtime: 52 ms, faster than 9.99% of C++ online submissions for Graph Valid Tree.
// Memory Usage: 13.4 MB, less than 44.35% of C++ online submissions for Graph Valid Tree.
    
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size()) return false;
        unordered_map<int, unordered_set<int>> g;
        for (const auto& e : edges) 
            g[e[0]].insert(e[1]),
            g[e[1]].insert(e[0]);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int cnt = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int p = q.front(); q.pop();
                for (int c : g[p]) {
                    if (visited[c]) {
                        if (!g[c].count(p))
                            return false;
                    } else {
                        q.push(c);
                        visited[c] = true;
                        ++cnt;
                    }
                }
            }
        }
        return cnt == n;
    }
};