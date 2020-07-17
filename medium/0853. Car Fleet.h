// 853. Car Fleet
// https://leetcode.com/problems/car-fleet/

// Runtime: 200 ms, faster than 8.03% of C++ online submissions for Car Fleet.
// Memory Usage: 26.2 MB, less than 5.79% of C++ online submissions for Car Fleet.

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // x0 + s0 * t >= x1 + s1 * t, x0 < x1
        // x0 + s0 * t <= target
        // s0 > s1 && t >= (x1 - x0) / (s0 - s1)
        if (position.empty()) return 0;
        vector<vector<int>> xs;
        for (int i = 0; i < position.size(); ++i)
            xs.push_back({position[i], speed[i]});
        sort(begin(xs), end(xs));
        vector<int> ans{0};
        for (int i = 1; i < xs.size(); ++i) {
            while (!ans.empty()) {
                int j = ans.back();
                // car_j can NOT catch up to car_i
                if (xs[j][1] <= xs[i][1]) break;
                
                double t = (xs[i][0] - xs[j][0]) / (double)(xs[j][1] - xs[i][1]);
                // car_j catchs up to car_i before/at target
                if (xs[i][0] + xs[i][1] * t <= target) ans.pop_back();
                else break;
            }
            ans.push_back(i);
        }
        return ans.size();
    }
};