// 871. Minimum Number of Refueling Stops
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

// Runtime: 208 ms, faster than 5.16% of C++ online submissions for Minimum Number of Refueling Stops.
// Memory Usage: 16.2 MB, less than 77.48% of C++ online submissions for Minimum Number of Refueling Stops.
    
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int n = stations.size();
        // dp[k] = max fuel when used k stops
        vector<int> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int k = i; k >= 0; --k) {
                // total fuel >= cur miles
                if (dp[k] >= stations[i][0]) {
                    // stop and refuel at stations[i]
                    int fuel = -target + dp[k] + stations[i][1] >= 0 ? target : dp[k] + stations[i][1];
                    dp[k + 1] = max(dp[k + 1], fuel);
                }
            }
        }
        
        for (int k = 0; k <= n; ++k) 
            if (dp[k] >= target)
                return k;
        return -1;
    }
};