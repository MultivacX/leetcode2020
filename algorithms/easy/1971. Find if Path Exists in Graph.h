// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/

// Runtime: 520 ms, faster than 60.75% of C++ online submissions for Find if Path Exists in Graph.
// Memory Usage: 149.1 MB, less than 61.83% of C++ online submissions for Find if Path Exists in Graph.
    
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (start == end) return true;
        
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n);
        visited[start] = true;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int i = q.front();
                q.pop();
                
                if (i == end) return true;
                
                for (int j : graph[i]) {
                    if (visited[j]) continue;
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        return false;
    }
};