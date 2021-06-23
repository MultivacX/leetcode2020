// 1906. Minimum Absolute Difference Queries
// https://leetcode.com/problems/minimum-absolute-difference-queries/

// Runtime: 312 ms, faster than 92.89% of C++ online submissions for Minimum Absolute Difference Queries.
// Memory Usage: 327.2 MB, less than 30.29% of C++ online submissions for Minimum Absolute Difference Queries.
    
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        vector<array<int, 101>> prefix{array<int, 101>{}};
        for (int i = 0; i < n; ++i) {
            prefix.emplace_back(prefix[i]);
            prefix[i + 1][nums[i]] = prefix[i][nums[i]] + 1;
        }
        
        const int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int k = INT_MAX;
            for (int j = 1, n1 = 0, n2 = 0; j <= 100; ++j) {
                int count = prefix[r][j] - prefix[l][j];
                if (count == 0) continue;
                if (n1 == 0) n1 = j;
                else if (n2 == 0) n2 = j;
                else { n1 = n2; n2 = j; }
                if (n2 > 0) k = min(k, n2 - n1);
            }
            ans[i] = k == INT_MAX ? -1 : k;
        }
        return ans;
    }
};