// 1066. Campus Bikes II
// https://leetcode.com/problems/campus-bikes-ii/

// Runtime: 8 ms, faster than 91.63% of C++ online submissions for Campus Bikes II.
// Memory Usage: 9.5 MB, less than 70.93% of C++ online submissions for Campus Bikes II.
    
class Solution {
    int distance(vector<vector<int>>& workers, vector<vector<int>>& bikes, int i, int j) {
        return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
    }
    
    int dfs(vector<vector<int>>& workers, 
             vector<vector<int>>& bikes, 
             vector<vector<int>>& memo, 
             int i, int bikeMask) {
        if (i >= workers.size()) return 0;
        if (memo[i][bikeMask] > 0) return memo[i][bikeMask];
        
        int ans = INT_MAX;
        for (int j = 0; j < bikes.size(); ++j) {
            if (bikeMask & (1 << j)) continue;
            ans = min(ans, distance(workers, bikes, i, j) + dfs(workers, bikes, memo, i + 1, bikeMask | (1 << j)));
        }
        memo[i][bikeMask] = ans;
        return ans;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> memo(workers.size(), vector<int>(1 << bikes.size(), 0));
        return dfs(workers, bikes, memo, 0, 0);
    }
};