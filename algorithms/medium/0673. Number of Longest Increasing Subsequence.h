// 673. Number of Longest Increasing Subsequence

// Runtime: 52 ms, faster than 72.09% of C++ online submissions for Number of Longest Increasing Subsequence.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Number of Longest Increasing Subsequence.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;
        
        int longest = 0;
        int ans = 0;
        vector<pair<int, int>> v(n, {0, 0});
        for (int i = 0; i < n; ++i) {
            int len = 0;
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (len == v[j].first) cnt += v[j].second;
                    else if (len < v[j].first) len = v[j].first, cnt = v[j].second;   
                }
            }
            v[i].first = ++len;
            v[i].second = cnt == 0 ? 1 : cnt;
            longest = max(longest, len);
        }
        for (int i = 0; i < n; ++i) {
            if (v[i].first == longest) ans += v[i].second;
        }
        return ans;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return N;
        
        // {cnt, len}
        vector<vector<int>> dp(N, vector<int>(2));
        for (int i = 0; i < N; ++i) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] >= nums[i]) continue;
                
                if (dp[j][1] + 1 > dp[i][1]) {
                    dp[i][0] = dp[j][0];
                    dp[i][1] = dp[j][1] + 1;
                } else if (dp[j][1] + 1 == dp[i][1]) {
                    dp[i][0] += dp[j][0];
                }
            }
            // cout << dp[i][1] << "*" << dp[i][0] << " ";
        }
        int maxLen = 1;
        for (int i = 0; i < N; ++i)
            if (maxLen < dp[i][1])
                maxLen = dp[i][1];
        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (maxLen == dp[i][1])
                ans += dp[i][0];
        return ans;
    }
};