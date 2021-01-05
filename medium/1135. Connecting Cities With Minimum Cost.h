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
        
        auto cmp = [&m](vector<int>& a, vector<int>& b) { return a[2] > b[2]; };
        using Q = priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>;
		Q q(cmp);
        
        vector<bool> visitedCities(N + 1, false);
        
        auto addEdges2Tree = [&](int i){
            if (visitedCities[i]) return;
            visitedCities[i] = true;
            
            for (auto it : m[i]) {
                int j = it.first;
                if (visitedCities[j]) continue;
                
                q.push({i, j, it.second});
                m[j].erase(i);
                if (m[j].empty())
                    m.erase(j);
            }
            m.erase(i);  
        };
        
        addEdges2Tree(1);
        
        int edges = 0;
        int cost = 0;
        while (!q.empty()) {
            int i = q.top()[0];
            int j = q.top()[1];
            int c = q.top()[2];
            q.pop();
            if (visitedCities[i] && visitedCities[j])
                continue;
            // cout << i << "--" << j << endl;
            addEdges2Tree(i);
            addEdges2Tree(j);
            ++edges;
            cost += c;
        }
        return edges + 1 == N ? cost : -1;
    }
};