// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// TLE
// 24 / 27 test cases passed.
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(begin(jobs), end(jobs));
        
        int ans = 0;
        map<int, int> dp; // dp[t] = max_profit(startTime >= t)
        for (int i = n - 1; i >= 0; --i) {
            auto it = dp.lower_bound(jobs[i][1]);
            int p = 0;
            while (it != dp.end()) {
                p = max(p, it->second);
                ++it;
            }
            dp[jobs[i][0]] = max(dp[jobs[i][0]], jobs[i][2] + p);
            ans = max(ans, dp[jobs[i][0]]);
        }
        return ans;
    }
};