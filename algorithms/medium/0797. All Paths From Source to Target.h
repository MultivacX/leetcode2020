// 797. All Paths From Source to Target

// Runtime: 68 ms, faster than 96.35% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for All Paths From Source to Target.

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int N = graph.size();
        
        vector<int> indegrees(N, 0);
        for (auto& children : graph)
            for (int child : children)
                ++indegrees[child];
        
        vector<vector<int>> ans;
        vector<int> path;
        for (int i = 0; i < indegrees.size(); ++i)
            if (indegrees[i] == 0)
                find(graph, i, path, ans);
        return ans;
    }
    
    void find(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& ans) {
        path.push_back(node);
        
        if (graph[node].empty()) {
            ans.push_back(path);
        } else {
            for (int child : graph[node])
                find(graph, child, path, ans);
        }
        
        path.pop_back();
    }
};