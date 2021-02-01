// 390. Elimination Game

// Runtime: 4 ms, faster than 80.71% of C++ online submissions for Elimination Game.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Elimination Game.

// Time Complexity: O(lgn).
// Space Complexity: O(1).

class Solution {
public:
    int lastRemaining(int n) {
        int L = 1;
        int R = n;
        int step = 1;
        bool L2R = true;
        while (L != R) {
            int next_step = step * 2;
            int next_L;
            int next_R;
            if (L2R) {
                next_L = L + step;
                next_R = (R - L) % next_step == 0 ? R - step : R;
            } else {
                next_R = R - step;
                next_L = (R - L) % next_step == 0 ? L + step : L;
            }
            L = next_L;
            R = next_R;
            step = next_step;
            L2R = !L2R;
        }
        return L;
    }
};