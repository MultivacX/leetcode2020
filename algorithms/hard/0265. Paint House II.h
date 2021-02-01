// 265. Paint House II
// https://leetcode.com/problems/paint-house-ii/

// Runtime: 28 ms, faster than 80.18% of C++ online submissions for Paint House II.
// Memory Usage: 11.2 MB, less than 83.78% of C++ online submissions for Paint House II.
    
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        const int n = costs.size();
        if (n <= 0) return 0;
        const int k = costs[0].size();
        if (n == 1) return *min_element(begin(costs[0]), end(costs[0]));
        if (k == 1) {
            int ans = 0;
            for (const auto& c : costs)
                ans += c[0];
            return ans;
        }
        
        vector<int> dp(costs[0]); // space optim : just use k0, k1 & c0, c1 replace dp
        for (int i = 1; i < n; ++i) {
            int k0 = 0, k1 = 1;
            for (int j = 1; j < k; ++j) {
                if (dp[j] < dp[k0]) {
                    k1 = k0;
                    k0 = j;
                } else if (dp[j] < dp[k1]) {
                    k1 = j;
                }
            }
            
            int c0 = dp[k0], c1 = dp[k1];
            for (int j = 0; j < k; ++j) 
                dp[j] = (j != k0 ? c0 : c1) + costs[i][j];
        }
        return *min_element(begin(dp), end(dp));
    }
};