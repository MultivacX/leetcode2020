// 1135. Connecting Cities With Minimum Cost
// https://leetcode.com/problems/connecting-cities-with-minimum-cost/

// Runtime: 356 ms, faster than 67.15% of C++ online submissions for Connecting Cities With Minimum Cost.
// Memory Usage: 55.1 MB, less than 34.79% of C++ online submissions for Connecting Cities With Minimum Cost.

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if (connections.size() < N - 1) return -1;
        
        // {city_i, {cost, city_j}}
        unordered_map<int, vector<pair<int, int>>> m; 
        for (const auto& v : connections) {
            m[v[0]].emplace_back(v[2], v[1]);
            m[v[1]].emplace_back(v[2], v[0]);
        }
        
        vector<int> minCostTo(N + 1, INT_MAX);
        unordered_set<int> visitedCities;
        
        // {cost, city_i}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        
        int ans = 0;
        while (visitedCities.size() < N && !q.empty()) {
            int cur_cost = q.top().first;
            int cur_city = q.top().second;
            q.pop();
            if (!visitedCities.insert(cur_city).second)
                continue;
            ans += cur_cost;
            
            for (const auto& p : m[cur_city]) {
                int cost = p.first;
                int city = p.second;
                if (minCostTo[city] > cost && !visitedCities.count(city)) {
                    minCostTo[city] = cost;
                    q.push(p);
                }
            }
        }
        return visitedCities.size() == N ? ans : -1;
    }
};