// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

// Runtime: 52 ms, faster than 18.70% of C++ online submissions for Meeting Rooms II.
// Memory Usage: 14 MB, less than 18.88% of C++ online submissions for Meeting Rooms II.
    
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        if (N <= 1) return N;
        
        map<int, int> m;
        for (const auto& i : intervals) 
            ++m[i[0]], --m[i[1]];
        int ans = 0, cnt = 0;
        for (auto it : m) {
            cnt += it.second;
            if (ans < cnt)
                ans = cnt;
        }
        return ans;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (const auto& i : intervals) {
            ++m[i[0]];
            --m[i[1]];
        }
        
        int ans = 0;
        int cnt = 0;
        for (auto it : m) {
            cnt += it.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};