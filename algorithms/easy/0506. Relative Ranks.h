// 506. Relative Ranks
// https://leetcode.com/problems/relative-ranks/

// Runtime: 48 ms, faster than 15.38% of C++ online submissions for Relative Ranks.
// Memory Usage: 11.6 MB, less than 19.23% of C++ online submissions for Relative Ranks.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> v(N, vector<int>{0, 0});
        for (int i = 0; i < N; ++i) {
            v[i][0] = nums[i];
            v[i][1] = i;
        }
        sort(rbegin(v), rend(v));
        vector<string> ans(N);
        for (int i = 0; i < N; ++i) {
            if (i == 0) ans[v[i][1]] = "Gold Medal";
            else if (i == 1) ans[v[i][1]] = "Silver Medal";
            else if (i == 2) ans[v[i][1]] = "Bronze Medal";
            else ans[v[i][1]] = to_string(i + 1);
        }
        return ans;
    }
};