// 759. Employee Free Time
// https://leetcode.com/problems/employee-free-time/

// Runtime: 56 ms, faster than 49.54% of C++ online submissions for Employee Free Time.
// Memory Usage: 12 MB, less than 34.25% of C++ online submissions for Employee Free Time.
    
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> m;
        for (const auto& v : schedule) {
            for (const auto& i : v) {
                ++m[i.start];
                --m[i.end];
            }
        }
        vector<Interval> ans;
        int t = 0;
        for (auto& it : m) {
            t += it.second;
            if (t == 0) 
                ans.emplace_back(it.first, -1);
            else if (t > 0 && !ans.empty() && ans.back().end == -1)
                ans.back().end = it.first;
        }
        if (!ans.empty() && ans.back().end == -1)
            ans.pop_back();
        return ans;
    }
};