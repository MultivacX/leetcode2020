// 780. Reaching Points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // tx - sx = A * sx + B * sy    A >= 0, B >= 0   
        // ty - sy = C * sx + D * sy    C >= 0, D >= 0
        
        if (sx > tx || sy > ty) return false;
        if (sx == tx && sy == ty) return true;
        if (sx == tx) return ty / sx * sx + sy == ty;
        if (sy == ty) return tx / sy * sy + sx == tx;
        
        return reachingPoints(sx + sy, sy, tx, ty) || reachingPoints(sx, sx + sy, tx, ty);
    }
};