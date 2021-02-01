// 56. Merge Intervals

// Runtime: 20 ms, faster than 74.58% of C++ online submissions for Merge Intervals.
// Memory Usage: 12.4 MB, less than 90.70% of C++ online submissions for Merge Intervals.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};