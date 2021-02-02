// 1274. Number of Ships in a Rectangle
// https://leetcode.com/problems/number-of-ships-in-a-rectangle/

// Runtime: 36 ms, faster than 68.70% of C++ online submissions for Number of Ships in a Rectangle.
// Memory Usage: 28.1 MB, less than 44.78% of C++ online submissions for Number of Ships in a Rectangle.

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x0 = bottomLeft[0], y0 = bottomLeft[1];
        int x1 = topRight[0], y1 = topRight[1];
        if (x0 > x1 || y0 > y1) return 0;
        if (!sea.hasShips(topRight, bottomLeft)) return 0;
        if (x0 == x1 && y0 == y1) return 1;
        
        int xm = x0 + (x1 - x0) / 2;
        int ym = y0 + (y1 - y0) / 2;
        return countShips(sea, {xm, ym}, {x0, y0}) +
               countShips(sea, {x1, ym}, {xm + 1, y0}) +
               countShips(sea, {xm, y1}, {x0, ym + 1}) +
               countShips(sea, {x1, y1}, {xm + 1, ym + 1});
    }
};