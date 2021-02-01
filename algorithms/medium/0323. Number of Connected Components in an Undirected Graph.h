// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

// Runtime: 60 ms, faster than 14.59% of C++ online submissions for Number of Connected Components in an Undirected Graph.
// Memory Usage: 17.3 MB, less than 6.34% of C++ online submissions for Number of Connected Components in an Undirected Graph.
    
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, unordered_set<int>> es;
        for (auto& e : edges) 
            es[e[0]].insert(e[1]), es[e[1]].insert(e[0]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            ++ans;
            if (!es.count(i)) continue;
            
            queue<int> q; 
            q.push(i);
            while (!q.empty()) {
                int size = q.size();
                while (size-- > 0) {
                    int j = q.front(); q.pop();
                    if (!es.count(j)) continue;
                    
                    for (int k : es[j]) {
                        if (visited[k]) continue;
                        
                        es[k].erase(j);
                        q.push(k);
                        visited[k] = true;
                    }
                    es.erase(j);
                }
            }
        }
        return ans;
    }
};