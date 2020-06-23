// 1443. Minimum Time to Collect All Apples in a Tree
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/

// Runtime: 340 ms, faster than 78.58% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.
// Memory Usage: 61 MB, less than 54.12% of C++ online submissions for Minimum Time to Collect All Apples in a Tree.

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        vector<int> path;
        vector<int> colors(n, 0);
        dfs(0, graph, hasApple, visited, path, colors);
        
        // for (int i = 0; i < n; ++i) cout << i << " "; cout << endl;
        // for (int i = 0; i < n; ++i) cout << colors[i] << " "; cout << endl;
        
        int cnt = 0;
        for (int c : colors) if (c > 0) ++cnt;
        return cnt > 0 ? (cnt - 1) * 2 : 0;
    }
    
    int dfs(int i, const vector<vector<int>>& graph, vector<bool>& hasApple, vector<bool>& visited, vector<int>& path, vector<int>& colors) {
        if (visited[i]) return colors[i];
        visited[i] = true;
        if (hasApple[i]) colors[i] = 2;
        
        int children_color = 0;
        for (int j : graph[i])
            if (!visited[j]) 
                children_color += dfs(j, graph, hasApple, visited, path, colors);
        
        if (!hasApple[i]) colors[i] = children_color > 0 ? 1 : 0;
        return colors[i];
    }
};