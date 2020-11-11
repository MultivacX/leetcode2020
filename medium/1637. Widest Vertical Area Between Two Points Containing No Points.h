// 1637. Widest Vertical Area Between Two Points Containing No Points
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

// Runtime: 764 ms, faster than 30.94% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.
// Memory Usage: 66.9 MB, less than 7.69% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int area = 0;
        sort(begin(points), end(points));
        for (int i = 1; i < points.size(); ++i) 
            area = max(area, points[i][0] - points[i - 1][0]);
        return area;
    }
};