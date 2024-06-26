// 3111. Minimum Rectangles to Cover Points

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());

        int res = 1;
        for (int i = 0, left = points[0][0]; i < points.size(); ++i) {
            if (points[i][0] - left > w) {
                // cout << left << ", " << points[i][0] << endl;
                res += 1;
                left = points[i][0];
            }
        }
        return res;
    }
};