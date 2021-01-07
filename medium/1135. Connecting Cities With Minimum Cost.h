// 1135. Connecting Cities With Minimum Cost
// https://leetcode.com/problems/connecting-cities-with-minimum-cost/

// WA: 55 / 63 test cases passed.

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if (connections.size() < N - 1) return -1;
        
        unordered_map<int, unordered_map<int, int>> m; 
        for (const auto& v : connections) {
            m[v[0]][v[1]] = v[2];
            m[v[1]][v[0]] = v[2];
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 1, 1});
        unordered_set<int> visited;
        
        auto addNextCities = [&](int i){
            if (!visited.insert(i).second) 
                return;
            
            for (auto it : m[i]) {
                int j = it.first;
                if (visited.count(j))
                    continue;
                int w = it.second;
                q.push({w, i, j});
            }
        };
        
        int cost = 0;
        while (!q.empty()) {
            int i = q.top()[1];
            int j = q.top()[2];
            int w = q.top()[0];
            q.pop();
            if (visited.count(i) && visited.count(j))
                continue;
            cost += w;
            addNextCities(i);
            addNextCities(j);
        }
        return visited.size() == N ? cost : -1;
    }
};