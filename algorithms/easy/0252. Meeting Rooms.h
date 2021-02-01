// 252. Meeting Rooms
// https://leetcode.com/problems/meeting-rooms/

// Runtime: 52 ms, faster than 18.40% of C++ online submissions for Meeting Rooms.
// Memory Usage: 12.3 MB, less than 32.76% of C++ online submissions for Meeting Rooms.
    
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        const int N = intervals.size();
        for (int i = 0; i + 1 < N; ++i)
            if (intervals[i][1] > intervals[i + 1][0])
                return false;
        return true;
    }
};