// 1232. Check If It Is a Straight Line

// Runtime: 12 ms, faster than 42.56% of C++ online submissions for Check If It Is a Straight Line.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Check If It Is a Straight Line.

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) return true;
     
        int i = 1;
        int dy = coordinates[i][1] - coordinates[i - 1][1];
        int dx = coordinates[i][0] - coordinates[i - 1][0];
        bool positive = true;
        // dy / dx
        if (dy != 0 && dx != 0) {
            positive = (dy > 0 && dx > 0) || (dy < 0 && dx < 0);
            int k = gcd(dy, dx);
            dy = abs(dy / k);
            dx = abs(dx / k);
        }
        for (i = 2; i < coordinates.size(); ++i) {
            int _dy = coordinates[i][1] - coordinates[i - 1][1];
            if (dy == 0) {
                if (_dy != 0) return false;
                continue;
            }
            
            int _dx = coordinates[i][0] - coordinates[i - 1][0];
            if (dx == 0) {
                if (_dx != 0) return false;
                continue;
            }
            
            bool _positive = (_dy > 0 && _dx > 0) || (_dy < 0 && _dx < 0);
            if (positive != _positive) return false;
            
            int _k = gcd(_dy, _dx);
            _dy = abs(_dy / _k);
            _dx = abs(_dx / _k);
            if (dy != _dy || dx != _dx) return false;
        }
        return true;
    }
};