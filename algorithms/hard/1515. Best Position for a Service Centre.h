// 1515. Best Position for a Service Centre
// https://leetcode.com/problems/best-position-for-a-service-centre/

// Runtime: 648 ms, faster than 5.10% of C++ online submissions for Best Position for a Service Centre.
// Memory Usage: 7.7 MB, less than 85.71% of C++ online submissions for Best Position for a Service Centre.
    
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        const int n = positions.size();
        if (n == 1) return 0;
        
        double x0 = 100, x1 = 0;
        double y0 = 100, y1 = 0;
        for (const auto& p : positions) {
            x0 = min(x0, (double)p[0]);
            x1 = max(x1, (double)p[0]);
            y0 = min(y0, (double)p[1]);
            y1 = max(y1, (double)p[1]);
        }
        
        double delta = 10;
        double ans = INT_MAX;
        while (delta >= 0.001) {
            double sum = INT_MAX;
            double tx, ty;
            for (double x = x0; x <= x1; x += delta) {
                for (double y = y0; y <= y1; y += delta) {
                    double cur = 0;
                    for (const auto& p : positions) {
                        double dx = x - p[0];
                        double dy = y - p[1];
                        cur += sqrt(dx * dx + dy * dy);
                    }
                    if (cur <= 0.00001) return cur;
                    if (cur < sum) {
                        sum = cur;
                        tx = x;
                        ty = y;
                    }
                }
            }
            if (sum <= ans) {
                x0 = tx - delta;
                x1 = tx + delta;
                y0 = ty - delta;
                y1 = ty + delta;
                ans = sum;
            }
            delta *= 0.1;
        }
        return ans;
    }
};