// 1319. Number of Operations to Make Network Connected

// Runtime: 184 ms, faster than 18.86% of C++ online submissions for Number of Operations to Make Network Connected.
// Memory Usage: 70.9 MB, less than 100.00% of C++ online submissions for Number of Operations to Make Network Connected.

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        const int e = connections.size();
        if (n > e + 1) return -1;
        
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        for (const auto& c : connections) {
            graph[c[0]].insert(c[1]);
            graph[c[1]].insert(c[0]);
        }
        vector<bool> visited(n, false);
        int group = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            ++group;
            
            deque<int> q;
            q.push_back(i);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int j = q.front();
                    q.pop_front();
                    
                    for (int k : graph[j]) {
                        if (visited[k]) continue;
                        visited[k] = true;
                        q.push_back(k);
                    }
                }
            }
        }
        
        return group - 1;
    }
};