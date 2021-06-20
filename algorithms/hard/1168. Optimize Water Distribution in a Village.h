// 1168. Optimize Water Distribution in a Village
// https://leetcode.com/problems/optimize-water-distribution-in-a-village/

// Runtime: 396 ms, faster than 14.34% of C++ online submissions for Optimize Water Distribution in a Village.
// Memory Usage: 37.9 MB, less than 64.15% of C++ online submissions for Optimize Water Distribution in a Village.
    
class Solution {
    int find(vector<int>& parents, int u) {
        if (parents[u] != u) 
            return find(parents, parents[u]);
        return u;
    }
    
    bool connect(vector<int>& parents, vector<int>& weights, int u, int v) {
        int parent_u = find(parents, parents[u]);
        int parent_v = find(parents, parents[v]);
        if (parent_u == parent_v) return false;
        
        if (weights[parent_u] >= weights[parent_v]) {
            weights[parent_u] += weights[parent_v];
            parents[parent_v] = parents[parent_u];
        } else {
            weights[parent_v] += weights[parent_u];
            parents[parent_u] = parents[parent_v];
        }
        return true;
    }
    
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // house[0] -> house[i]
        for (int i = 1; i <= n; ++i)
            pipes.push_back({0, i, wells[i - 1]});
        sort(begin(pipes), end(pipes), [](const vector<int>& l, const vector<int>& r){
            return l.back() > r.back();
        });
        
        // union find
        vector<int> parents(n + 1), weights(n + 1);
        for (int i = 1; i <= n; ++i)
            parents[i] = i;
        
        int ans = 0;
        while (!pipes.empty()) {
            int u = pipes.back()[0];
            int v = pipes.back()[1];
            int w = pipes.back()[2];
            pipes.pop_back();
            if (connect(parents, weights, u, v))
                ans += w;
        }
        return ans;
    }
};