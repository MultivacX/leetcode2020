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


class Solution {
    bool overlap(int s1, int e1, int s2, int e2) {
        return (s1 <= s2 && s2 <= e1) || (s2 <= s1 && s1 <= e2);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        
        vector<vector<int>> ans;
        bool merged = false;
        for (const auto& interval : intervals) {
            int s1 = interval[0], e1 = interval[1];
            if (!merged) {
                int s2 = newInterval[0], e2 = newInterval[1];
                if (overlap(s1, e1, s2, e2)) {
                    ans.push_back({min(s1, s2), max(e1, e2)});
                    merged = true;
                } else if (e2 < s1) {
                    ans.push_back(newInterval);
                    ans.push_back(interval);
                    merged = true;
                } else ans.push_back(interval);
            } else {
                int &s2 = ans.back()[0], &e2 = ans.back()[1];
                if (overlap(s1, e1, s2, e2)) s2 = min(s1, s2), e2 = max(e1, e2);
                else ans.push_back(interval);
            }
        }
        if (!merged) ans.push_back(newInterval);
        return ans;
    }
};