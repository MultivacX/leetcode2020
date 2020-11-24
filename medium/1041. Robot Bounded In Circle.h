// 1041. Robot Bounded In Circle
// https://leetcode.com/problems/robot-bounded-in-circle/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
// Memory Usage: 6.3 MB, less than 92.21% of C++ online submissions for Robot Bounded In Circle.
    
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        // L:--d, R:++d
        const int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (char i : instructions) {
            if (i == 'G') x += D[d][0], y += D[d][1];
            else d = (i == 'R' ? d + 1 : d + 3) % 4;
            // cout << d << ":(" << x << ',' << y << ")  ";
        }
        if (d != 0) return true;
        return x == 0 && y == 0;
    }
};