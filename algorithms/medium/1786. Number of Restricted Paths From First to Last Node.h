// 1786. Number of Restricted Paths From First to Last Node
// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

// Runtime: 516 ms, faster than 56.91% of C++ online submissions for Number of Restricted Paths From First to Last Node.
// Memory Usage: 155.7 MB, less than 34.44% of C++ online submissions for Number of Restricted Paths From First to Last Node.
    
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        static const int64_t M = 1000000007; 
        
        using A2 = array<int, 2>;
        
        vector<vector<A2>> g(n + 1);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
            
        vector<int> dist(n + 1, INT_MAX - 10000);
        dist[n] = 0;
        
        priority_queue<A2, vector<A2>, greater<A2>> q;
        q.push({0, n});
        
        while (!q.empty()) {
            int u = q.top()[1], d = q.top()[0];
            q.pop();
            if (d > dist[u]) continue;
            
            for (const auto& a : g[u]) {
                int v = a[1], w = a[0];
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        vector<int> dp(n + 1, INT_MAX);
        function<int(int)> dfs = [&](int u){
            if (u == n) return 1;
            if (dp[u] != INT_MAX) return dp[u];
            int ans = 0;
            for (const auto& a : g[u]) {
                int v = a[1];
                if (dist[u] > dist[v])
                    ans = (ans + dfs(v)) % M;
            }
            dp[u] = ans;
            return ans;
        };
        return dfs(1);
    }
};