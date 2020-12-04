// 1229. Meeting Scheduler
// https://leetcode.com/problems/meeting-scheduler/

// Runtime: 448 ms, faster than 27.96% of C++ online submissions for Meeting Scheduler.
// Memory Usage: 40.4 MB, less than 86.02% of C++ online submissions for Meeting Scheduler.
    
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(begin(slots1), end(slots1));
        sort(begin(slots2), end(slots2));
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            int s1 = slots1[i][0], e1 = slots1[i][1];
            int s2 = slots2[j][0], e2 = slots2[j][1];
            int d = min(e1, e2) - max(s1, s2);
            if (d >= duration) return {max(s1, s2), max(s1, s2) + duration};
            if (e1 == e2) ++i, ++j;
            else e1 < e2 ? ++i : ++j;
        }
        return {};
    }
};