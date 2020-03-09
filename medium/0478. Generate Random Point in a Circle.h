// 478. Generate Random Point in a Circle

// Runtime: 152 ms, faster than 30.28% of C++ online submissions for Generate Random Point in a Circle.
// Memory Usage: 26.6 MB, less than 100.00% of C++ online submissions for Generate Random Point in a Circle.

class Solution {
public:
    static constexpr double pi() { return std::atan(1) * 4; } 
    
    Solution(double radius, double x_center, double y_center)
    : r(radius)
    , xc(x_center) 
    , yc(y_center) {
        srand((unsigned)time(NULL)); 
    }
    
    vector<double> randPoint() {
        // double area = pi() * r * r * rand() / double(RAND_MAX);
        // double _r = sqrt(area / pi());
        double _r = r * sqrt(rand() / double(RAND_MAX));
        double _o = 2.0 * pi() * rand() / double(RAND_MAX);
        return {xc + _r * cos(_o), yc + _r * sin(_o)};
    }
    
    double r;
    double xc;
    double yc;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */