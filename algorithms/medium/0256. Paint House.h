// 256. Paint House
// https://leetcode.com/problems/paint-house/

// Runtime: 32 ms, faster than 6.46% of C++ online submissions for Paint House.
// Memory Usage: 10 MB, less than 69.98% of C++ online submissions for Paint House.
    
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r = 0, b = 0, g = 0;
        for (const auto& c : costs) {
            int cur_r = c[0] + min(b, g);
            int cur_b = c[1] + min(r, g);
            int cur_g = c[2] + min(b, r);
            r = cur_r;
            b = cur_b;
            g = cur_g;
        }
        return min(r, min(b, g));
    }
};