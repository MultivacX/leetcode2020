// 1182. Shortest Distance to Target Color
// https://leetcode.com/problems/shortest-distance-to-target-color/

// Runtime: 636 ms, faster than 75.00% of C++ online submissions for Shortest Distance to Target Color.
// Memory Usage: 121.2 MB, less than 78.95% of C++ online submissions for Shortest Distance to Target Color.
    
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> colours(4, vector<int>{});
        for (int i = 0; i < colors.size(); ++i)
            colours[colors[i]].push_back(i);
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            const auto& c = colours[queries[i][1]];
            if (0 == c.size()) continue;
            int t = queries[i][0];
            int j = lower_bound(begin(c), end(c), t) - begin(c);
            ans[i] = j > 0 ? abs(c[j - 1] - t) : INT_MAX;
            if (j < c.size()) ans[i] = min(ans[i], c[j] - t);
        }
        return ans;
    }
};