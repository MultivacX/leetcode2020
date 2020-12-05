// 1059. All Paths from Source Lead to Destination
// https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

// Runtime: 148 ms, faster than 56.38% of C++ online submissions for All Paths from Source Lead to Destination.
// Memory Usage: 36.7 MB, less than 20.21% of C++ online submissions for All Paths from Source Lead to Destination.
    
class Solution {
    unordered_map<int, unordered_set<int>> m;
    int d;
    
    bool dfs(vector<bool>& visited, int s) {
        if (s == d) return true;
        if (visited[s]) return false;
        visited[s] = true;
        bool b = false;
        for (int i : m[s]) {
            b = dfs(visited, i);
            if (!b) return false;
        }
        visited[s] = false;
        return b;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for (const auto& e : edges) {
            if (e[0] == destination) 
                return false;
            m[e[0]].insert(e[1]);
        }
        d = destination;
        vector<bool> visited(n, false);
        return dfs(visited, source);
    }
};