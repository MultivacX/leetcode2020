// 57. Insert Interval

// Runtime: 12 ms, faster than 97.47% of C++ online submissions for Insert Interval.
// Memory Usage: 12.5 MB, less than 55.00% of C++ online submissions for Insert Interval.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) return intervals;
        if (intervals.empty()) return {newInterval};
        
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        if (it == intervals.end()) {
            _insert(intervals, newInterval); 
            return intervals;
        }
        
        vector<vector<int>> ans;
        bool inserted = false;
        for (auto i = intervals.begin(); i != intervals.end(); ++i) {
            if (ans.empty()) {
                if (i == it) {
                    inserted = true;
                    ans.push_back(newInterval);    
                    _insert(ans, *i);
                } else {
                    ans.push_back(*i);
                }
            } else if (inserted) {
                _insert(ans, *i);
            } else {
                if (i == it) {
                    inserted = true;
                    _insert(ans, newInterval);    
                    _insert(ans, *i);
                } else {
                    ans.push_back(*i);
                }
            }
        }
        return ans;
    }
    
    void _insert(vector<vector<int>>& ans, vector<int>& interval) {
        if (ans.back()[1] >= interval[0]) {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        } else {
            ans.push_back(interval);
        }
    }
};