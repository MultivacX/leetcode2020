// 1377. Frog Position After T Seconds

// Runtime: 32 ms, faster than 47.17% of C++ online submissions for Frog Position After T Seconds.
// Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Frog Position After T Seconds.

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<bool> visited(n + 1, false);
        vector<vector<int>> v(n + 1, vector<int>());
        for (const auto& edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        return find(visited, v, t, target, 1, 1);
    }
    
    double find(vector<bool>& visited, vector<vector<int>>& v, int t, int target, int i, double p) {
        if (t == 0) return target == i ? p : 0;
        
        visited[i] = true;
        int children_count = 0;
        for (int j : v[i]) if (!visited[j]) ++children_count;
        if (children_count == 0) return target == i ? p : 0;
        
        double ans = 0;
        for (int j : v[i]) if (!visited[j]) ans += find(visited, v, t - 1, target, j, p / children_count);
        return ans;
    }
};