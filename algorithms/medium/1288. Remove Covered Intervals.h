// 1288. Remove Covered Intervals

// Runtime: 36 ms, faster than 45.12% of C++ online submissions for Remove Covered Intervals.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Remove Covered Intervals.

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](vector<int>& l, vector<int>& r){
            return l[1] > r[1] || (l[1] == r[1] && l[0] < r[0]);
        });
        
        vector<vector<int>> new_intervals;
        for (const auto& i : intervals) {
            if (new_intervals.empty()) {
                new_intervals.push_back(i);
            } else if (new_intervals.back()[0] <= i[0] && new_intervals.back()[1] >= i[1]) {
                continue;
            } else {
                new_intervals.push_back(i);
            }
        }
        return new_intervals.size();
    }
};