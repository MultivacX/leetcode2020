// 1629. Slowest Key
// https://leetcode.com/problems/slowest-key/

// Runtime: 12 ms, faster than 88.81% of C++ online submissions for Slowest Key.
// Memory Usage: 10.8 MB, less than 96.10% of C++ online submissions for Slowest Key.

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int t = releaseTimes[0];
        char c = keysPressed[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            int t_ = releaseTimes[i] - releaseTimes[i - 1];
            if (t_ > t) {
                t = t_;
                c = keysPressed[i];
            } else if (t_ == t && c < keysPressed[i]) { 
                c = keysPressed[i];
            }
        }
        return c;
    }
};