// 1575. Count All Possible Routes
// https://leetcode.com/problems/count-all-possible-routes/

// Runtime: 216 ms, faster than 38.86% of C++ online submissions for Count All Possible Routes.
// Memory Usage: 12 MB, less than 41.97% of C++ online submissions for Count All Possible Routes.
    
class Solution {
    int helper(vector<int>& locations, int cur, int finish, int fuel, vector<vector<int>>& memo) {
        if (fuel < 0) return 0;
        if (memo[cur][fuel] != -1) return memo[cur][fuel];
        int routes = cur == finish ? 1 : 0;
        for (int i = 0; i < locations.size(); ++i) {
            if (i == cur) continue;
            routes = (routes + helper(locations, i, finish, fuel - abs(locations[i] - locations[cur]), memo)) % 1000000007;
        }
        memo[cur][fuel] = routes;
        return routes;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> memo(locations.size(), vector<int>(fuel + 1, -1));
        return helper(locations, start, finish, fuel, memo);
    }
};