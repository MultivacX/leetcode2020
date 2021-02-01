// 1344. Angle Between Hands of a Clock

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Angle Between Hands of a Clock.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Angle Between Hands of a Clock.

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = 360.0 * minutes / 60.0;
        double h = hour % 12 * 360.0 / 12.0 + 360.0 / 12.0 * minutes / 60.0;
        return min(max(m, h) - min(m, h), 360.0 - max(m, h) + min(m, h));
    }
};