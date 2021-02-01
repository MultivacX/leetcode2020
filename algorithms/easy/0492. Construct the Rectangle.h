// 492. Construct the Rectangle
// https://leetcode.com/problems/construct-the-rectangle/

// Runtime: 76 ms, faster than 13.74% of C++ online submissions for Construct the Rectangle.
// Memory Usage: 6.6 MB, less than 14.22% of C++ online submissions for Construct the Rectangle.

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = 1;
        int L = area;
        for (L = sqrt(area); L <= area; ++L) {
            W = area / L;
            if (L * W == area) break;
        }
        return {max(L, W), min(L, W)};
    }
};