// 1646. Get Maximum in Generated Array
// https://leetcode.com/problems/get-maximum-in-generated-array/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Get Maximum in Generated Array.
// Memory Usage: 6.6 MB, less than 50.00% of C++ online submissions for Get Maximum in Generated Array.

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) 
            dp[i] = (i & 1) == 0 ? dp[i / 2] : dp[i / 2] + dp[i / 2 + 1];
        return *max_element(begin(dp), end(dp));
    }
};