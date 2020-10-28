// 1595. Minimum Cost to Connect Two Groups of Points
// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/

class Solution {
    using arr = array<int, 3>;
    
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        auto cmp = [](arr& l, arr& r) { return l.back() > r.back(); };
        priority_queue<arr, vector<arr>, decltype(cmp)> q(cmp);
        for (int i = 0; i < cost.size(); ++i) {
            for (int j = 0; j < cost[i].size(); ++j) {
                q.push({i, j, cost[i][j]});
            }
        }
        
        
        int ans = 0;
        while (!q.empty()) {
            int i = q.top()[0];
            int j = q.top()[1];
            int c = q.top()[2];
            q.pop();
                
            
        }
        return ans;
    }
};