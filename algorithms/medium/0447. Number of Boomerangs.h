// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/

// Runtime: 1032 ms, faster than 30.71% of C++ online submissions for Number of Boomerangs.
// Memory Usage: 124.9 MB, less than 5.08% of C++ online submissions for Number of Boomerangs.

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        const int N = points.size();
        int ans = 0;
        // b[i] = {{distance^2: cnt}, ..}
        vector<unordered_map<int, int>> b(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int dist2 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
                          + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                ++b[i][dist2];
                ++b[j][dist2];
            }
            for (auto it : b[i]) {
                // j <-- i --> k
                if (it.second == 1) continue;
                ans += (it.second - 1) * it.second;
            }
        }
        return ans;
    }
};