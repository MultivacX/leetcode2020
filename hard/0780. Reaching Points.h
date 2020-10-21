// 780. Reaching Points
// https://leetcode.com/problems/reaching-points/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reaching Points.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Reaching Points.

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx > ty) tx %= ty;
            else ty %= tx;
        }
        // sx == tx and k * sx + sy == ty, k >= 0
        // sy == ty and k * sy + sx == tx, k >= 0
        return (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
               (sy == ty && sx <= tx && (tx - sx) % sy == 0);
    }
};