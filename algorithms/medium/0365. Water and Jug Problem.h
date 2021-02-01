// 365. Water and Jug Problem

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Water and Jug Problem.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Water and Jug Problem.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Water and Jug Problem.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Water and Jug Problem.

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int64_t X = abs(x);
        int64_t Y = abs(y);
        int64_t Z = abs(z);
        if (X + Y < Z) return false;
        if (X == Z || Y == Z || X + Y == Z) return true;
        return Z % gcd(X, Y) == 0;
    }
};