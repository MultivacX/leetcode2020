// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// Runtime: 1012 ms, faster than 10.97% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
// Memory Usage: 182.1 MB, less than 5.03% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
    
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> a2b;
        unordered_map<int, unordered_set<int>> aFb;
        for (const auto& c : connections) {
            int a = c[0], b = c[1];
            a2b[a].insert(b);
            aFb[b].insert(a);
        }
        
        int ans = 0;
        unordered_set<int> visited;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                int a = q.front(); q.pop();
                visited.insert(a);
                
                if (a2b.count(a)) {
                    for (int b : a2b[a]) {
                        if (visited.count(b)) continue;
                        aFb[a].insert(b);
                        ++ans;
                    }
                    a2b.erase(a);
                }
                
                if (aFb.count(a)) {
                    for (int b : aFb[a]) {
                        if (visited.count(b)) continue;
                        q.push(b);
                    }
                    aFb.erase(a);
                }
            }
        }
        return ans;
    }
};