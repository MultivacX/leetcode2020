// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// Runtime: 396 ms, faster than 7.82% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.
// Memory Usage: 22.8 MB, less than 5.13% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, unordered_map<int, int>> m;
        for (auto e : edges) {
            m[e[0]][e[1]] = e[2];
            m[e[1]][e[0]] = e[2];
        }
        
        auto cmp = [](array<int, 2>& left, array<int, 2>& right) { return left.back() > right.back(); };
        
        vector<int> neighbores(n, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> dists(n, distanceThreshold + 1);
            priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> q(cmp);
            q.push({i, 0}); 
            while (!q.empty()) {
                int j = q.top()[0];
                int w = q.top()[1];
                q.pop();
                
                if (w >= dists[j]) continue;
                dists[j] = w;
                
                for (auto kw : m[j]) {
                    int k = kw.first;
                    int next_w = w + kw.second;
                    if (next_w >= dists[k]) continue;
                    q.push({k, next_w}); 
                }
            }
            
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                if (dists[j] <= distanceThreshold) ++cnt;
            neighbores[i] = cnt - 1;
            
            // cout << i << ":";
            // for (int j = 0; j < n; ++j) cout << " [" << j << "]:" << dists[j]; 
            // cout << " | " << neighbores[i] << endl;
        }
        
        int cnt = neighbores[0];
        int city = 0;
        for (int i = 1; i < n; ++i) 
            if (cnt >= neighbores[i]) cnt = neighbores[i], city = i;
        return city;
    }
};