// 960. Delete Columns to Make Sorted III
// https://leetcode.com/problems/delete-columns-to-make-sorted-iii/

// Runtime: 16 ms, faster than 90.07% of C++ online submissions for Delete Columns to Make Sorted III.
// Memory Usage: 10.4 MB, less than 52.32% of C++ online submissions for Delete Columns to Make Sorted III.
    
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs.size();
        const int m = strs[0].size();
        
        int ans = m;
        vector<int> dp(m, 1);
        for (int r = 1; r < m; ++r) {
            // dp[r] = min( LIS(strs[i][0, ..., r]) )
            for (int l = r - 1; l >= 0; --l) {
                int lis = 1;
                bool b = true;
                for (const auto& s : strs) {
                    if (s[l] > s[r]) {
                        b = false;
                        break;
                    }
                    lis = max(lis, dp[l] + 1);
                }
                if (b) dp[r] = max(dp[r], lis);
            }
            ans = min(ans, m - dp[r]);
        }
        return ans == m ? 0 : ans;
    }
};