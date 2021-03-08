// 1779. Find Nearest Point That Has the Same X or Y Coordinate
// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

// Runtime: 152 ms, faster than 100.00% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
// Memory Usage: 59.3 MB, less than 100.00% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
    
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int dist = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            if (x != points[i][0] && y != points[i][1])
                continue;
            int d = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (dist > d) dist = d, ans = i;
        }
        return ans;
    }
};