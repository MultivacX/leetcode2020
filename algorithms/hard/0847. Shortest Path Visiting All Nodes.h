// 847. Shortest Path Visiting All Nodes
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

// Runtime: 32 ms, faster than 51.78% of C++ online submissions for Shortest Path Visiting All Nodes.
// Memory Usage: 12.1 MB, less than 62.22% of C++ online submissions for Shortest Path Visiting All Nodes.
    
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int N = graph.size();
        const int M = (1 << N) - 1;
        
        // (current_node << N) | mask
        unordered_set<int> visited;
        
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            int key = (i << N) | (1 << i);
            visited.insert(key);
            q.emplace(key);
        }
        
        int cost = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int mask = q.front() & M;
                if (mask == M) return cost;
                
                int i = q.front() >> N;
                q.pop();
                
                for (int j : graph[i]) {
                    // move from i to j
                    int key = (j << N) | ((1 << j) | mask);
                    if (!visited.insert(key).second) continue;
                    q.emplace(key);
                }
            }
            ++cost;
        }
        return cost;
    }
};