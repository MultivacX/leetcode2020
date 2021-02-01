// 812. Largest Triangle Area
// https://leetcode.com/problems/largest-triangle-area/

// Runtime: 8 ms, faster than 98.28% of C++ online submissions for Largest Triangle Area.
// Memory Usage: 8 MB, less than 43.64% of C++ online submissions for Largest Triangle Area.

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        const int N = points.size();
        for (int i = 0; i < N - 2; ++i) {
            for (int j = i + 1; j < N - 1; ++j) {
                int x0 = points[i][0] - points[j][0];
                int y0 = points[i][1] - points[j][1];
                for (int k = j + 1; k < N; ++k) {
                    int x1 = points[i][0] - points[k][0];
                    int y1 = points[i][1] - points[k][1];
                    area = max(area, 0.5 * abs(x0 * y1 - x1 * y0));
                }
            }
        }
        return area;
    }
};