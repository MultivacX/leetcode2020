// 1620. Coordinate With Maximum Network Quality
// https://leetcode.com/problems/coordinate-with-maximum-network-quality/

// Runtime: 76 ms, faster than 55.33% of C++ online submissions for Coordinate With Maximum Network Quality.
// Memory Usage: 9.2 MB, less than 7.85% of C++ online submissions for Coordinate With Maximum Network Quality.

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xmin = 50;
        int xmax = 0;
        int ymin = 50;
        int ymax = 0;
        for (const auto& t : towers) {
            xmin = min(xmin, t[0]);
            xmax = max(xmax, t[0]);
            ymin = min(ymin, t[1]);
            ymax = max(ymax, t[1]);
        }
        
        int qmax = 0;
        int xans = 0;
        int yans = 0;
        for (int x = xmin; x <= xmax; ++x) {
            for (int y = ymin; y <= ymax; ++y) {
                int q = 0;
                for (const auto& t : towers) {
                    int d = (x - t[0]) * (x - t[0]) + (y - t[1]) * (y - t[1]);
                    if (d > radius * radius) continue;
                    q += t[2] / (1.0 + sqrt(d));
                }
                if (qmax < q) {
                    qmax = q;
                    xans = x;
                    yans = y;
                }
            }
        }
        return {xans, yans};
    }
};