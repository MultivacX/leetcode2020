// 1266. Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/

// Runtime: 4 ms, faster than 99.93% of C++ online submissions for Minimum Time Visiting All Points.
// Memory Usage: 10.4 MB, less than 98.80% of C++ online submissions for Minimum Time Visiting All Points.
    
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i + 1 < points.size(); ++i) 
            ans += max(abs(points[i + 1][0] - points[i][0]), 
                       abs(points[i + 1][1] - points[i][1]));
        return ans;
    }
};