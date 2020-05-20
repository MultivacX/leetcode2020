// 1037. Valid Boomerang

// Runtime: 8 ms, faster than 36.27% of C++ online submissions for Valid Boomerang.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Valid Boomerang.

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int AB_x = points[0][0] - points[1][0];
        int AB_y = points[0][1] - points[1][1];
        
        int AC_x = points[0][0] - points[2][0];
        int AC_y = points[0][1] - points[2][1];
        
        int dot_product = AB_x * AC_x + AB_y * AC_y;
        
        return dot_product * dot_product != (AB_x * AB_x + AB_y * AB_y) * (AC_x * AC_x + AC_y * AC_y);
    }
};