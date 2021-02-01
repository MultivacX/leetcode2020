// 435. Non-overlapping Intervals

// Runtime: 16 ms, faster than 69.75% of C++ online submissions for Non-overlapping Intervals.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Non-overlapping Intervals.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        int ans = 0;
        int cur = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[cur][0] == intervals[i][0]) {
                // cur.start == i.start
                // cur.end >= i.end
                ++ans;
                cur = i;
            } else if (intervals[cur][1] > intervals[i][0]) {
                // cur.start < i.start
                // cur.end > i.start
                ++ans;
                if (intervals[cur][1] >= intervals[i][1]) {
                    // cur.end >= i.end
                    cur = i;
                }
            } else {
                cur = i;
            }
        }
        return ans;
    }
};