// 1401. Circle and Rectangle Overlapping

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Circle and Rectangle Overlapping.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Circle and Rectangle Overlapping.

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (x2 < x_center - radius || x1 > x_center + radius) return false;
        if (y2 < y_center - radius || y1 > y_center + radius) return false;
        
        if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) return true;
        
        auto distance2 = [](int xc, int yc, int x, int y){ return (xc - x) * (xc - x) + (yc - y) * (yc - y); };
        if (distance2(x_center, y_center, x1, y1) <= radius * radius) return true;
        if (distance2(x_center, y_center, x1, y2) <= radius * radius) return true;
        if (distance2(x_center, y_center, x2, y1) <= radius * radius) return true;
        if (distance2(x_center, y_center, x2, y2) <= radius * radius) return true;
        
        auto resolution = [](double ic, double r, double j, double jc){ 
            double root = sqrt(r * r - (j - jc) * (j - jc));
            return vector<double>{ic + root, ic - root}; 
        };
        auto ys = resolution(y_center, radius, x1, x_center);
        if (y1 <= ys[0] && ys[0] <= y2) return true;
        if (y1 <= ys[1] && ys[1] <= y2) return true;
        
        ys = resolution(y_center, radius, x2, x_center);
        if (y1 <= ys[0] && ys[0] <= y2) return true;
        if (y1 <= ys[1] && ys[1] <= y2) return true;
        
        auto xs = resolution(x_center, radius, y1, y_center);
        if (x1 <= xs[0] && xs[0] <= x2) return true;
        if (x1 <= xs[1] && xs[1] <= x2) return true;
        
        xs = resolution(x_center, radius, y2, y_center);
        if (x1 <= xs[0] && xs[0] <= x2) return true;
        if (x1 <= xs[1] && xs[1] <= x2) return true;
        
        return false;
    }
};