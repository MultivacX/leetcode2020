// 1692. Count Ways to Distribute Candies
// https://leetcode.com/problems/count-ways-to-distribute-candies/

// Runtime: 80 ms, faster than 94.59% of C++ online submissions for Count Ways to Distribute Candies.
// Memory Usage: 10.4 MB, less than 81.08% of C++ online submissions for Count Ways to Distribute Candies.
    
class Solution {
    static const int64_t M = 1000000007;
    int dp[1001][1001] = {0};
    
public:
    int waysToDistribute(int n, int k) {
        if (n == k || 1 == k) return 1;
        if (n < k) return 0;
        if (n <= 0 || k <= 0) return 0;
        
        if (dp[n][k] != 0) return dp[n][k];
        
        int64_t ans = ((int64_t)waysToDistribute(n - 1, k) * (int64_t)k % M +
                       (int64_t)waysToDistribute(n - 1, k - 1)) % M; 
        dp[n][k] = ans;
        return ans;
    }
};