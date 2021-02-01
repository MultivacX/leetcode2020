// 785. Is Graph Bipartite?

// Runtime: 24 ms, faster than 82.29% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 11.3 MB, less than 53.85% of C++ online submissions for Is Graph Bipartite?.

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        if (N <= 2) return true;
        
        vector<int> shaders(N, 0);
        for (int i = 0; i < N; ++i) {
            if (shaders[i] != 0)
                continue;
            
            int color = 1;
            deque<int> q;
            q.push_back(i);
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    int k = q.front();
                    q.pop_front();
                    if (shaders[k] == 0) {
                        shaders[k] = color;
                        for (int j : graph[k])
                            q.push_back(j);
                    } else if (shaders[k] != color) {
                        return false;
                    }
                }
                color *= -1;
            }
        }
        // for (int i = 0; i < N; ++i) cout << i << ":" << shaders[i] << ", ";
        return true;
    }
};