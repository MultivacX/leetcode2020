// 1335. Minimum Difficulty of a Job Schedule
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

// Runtime: 308 ms, faster than 10.70% of C++ online submissions for Minimum Difficulty of a Job Schedule.
// Memory Usage: 95.2 MB, less than 5.69% of C++ online submissions for Minimum Difficulty of a Job Schedule.
    
class Solution {
    const int MAX = 300001;
    
    int dp(const vector<int>& jobDifficulty, int d, int i, int j, vector<vector<vector<int>>>& memo) {
        if (d <= 0 || i > j) return MAX;
        if (i == j) return d == 1 ? jobDifficulty[i] : MAX;
        if (memo[i][j][d] != MAX) return memo[i][j][d];
        if (d == 1) return memo[i][j][d] = *max_element(begin(jobDifficulty) + i, begin(jobDifficulty) + j + 1);
        
        int ans = MAX;
        for (int k = i, v = jobDifficulty[k]; k < j - d + 2; ++k) {
            v = max(v, jobDifficulty[k]);
            ans = min(ans, v + dp(jobDifficulty, d - 1, k + 1, j, memo));
        }
        return memo[i][j][d] = ans;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n = jobDifficulty.size();
        if (n < d) return -1;
        if (n == d) return accumulate(begin(jobDifficulty), end(jobDifficulty), 0);
        
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(d + 1, MAX)));
        return dp(jobDifficulty, d, 0, n - 1, memo);
    }
};