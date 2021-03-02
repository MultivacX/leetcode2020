// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Runtime: 168 ms, faster than 70.60% of C++ online submissions for Maximum Profit in Job Scheduling.
// Memory Usage: 57.7 MB, less than 60.89% of C++ online submissions for Maximum Profit in Job Scheduling.
    
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            jobs[i][0] = endTime[i];
            jobs[i][1] = startTime[i];
            jobs[i][2] = profit[i];
        }
        sort(begin(jobs), end(jobs));
        
        map<int, int> dp{{0, 0}}; // dp[t] = max_profit(endTime <= t)
        for (int i = 0; i < n; ++i) {
            int s = jobs[i][1];
            int e = jobs[i][0];
            int p = jobs[i][2];
            
            auto it = prev(dp.upper_bound(s));
            int cur_p = it->second + p;
            if (cur_p > dp.crbegin()->second)
                dp[e] = cur_p;
        }
        return dp.crbegin()->second;
    }
};


// Runtime: 160 ms, faster than 74.94% of C++ online submissions for Maximum Profit in Job Scheduling.
// Memory Usage: 57.5 MB, less than 61.67% of C++ online submissions for Maximum Profit in Job Scheduling.
    
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
        
        map<int, int> dp{{INT_MAX, 0}}; // dp[t] = max_profit(startTime >= t)
        for (int i = n - 1; i >= 0; --i) {
            auto it = dp.lower_bound(jobs[i][1]);
            int cur_p = it->second + jobs[i][2];
            if (cur_p > dp.cbegin()->second)
                dp[jobs[i][0]] = cur_p;
        }
        return dp.cbegin()->second;
    }
};


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