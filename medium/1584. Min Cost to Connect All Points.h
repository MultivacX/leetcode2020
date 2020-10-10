// 1584. Min Cost to Connect All Points
// https://leetcode.com/problems/min-cost-to-connect-all-points/

// Runtime: 200 ms, faster than 85.22% of C++ online submissions for Min Cost to Connect All Points.
// Memory Usage: 10.3 MB, less than 5.20% of C++ online submissions for Min Cost to Connect All Points.

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        vector<int> to(N, INT_MAX);
        vector<bool> visited(N, false);
        int curIdx = 0;
        int cost = 0;
        // Prim
        for (int i = 0; i + 1 < N; ++i) {
            int x = points[curIdx][0];
            int y = points[curIdx][1];
            visited[curIdx] = true;
            for (int j = 0; j < N; ++j) {
                if (visited[j]) continue;
                to[j] = min(to[j], abs(x - points[j][0]) + abs(y - points[j][1]));
            }
            // for (int j = 0; j < N; ++j) cout << to[j] << " "; cout << endl;
            curIdx = distance(begin(to), min_element(begin(to), end(to)));
            cost += to[curIdx];
            to[curIdx] = INT_MAX;
            // for (int j = 0; j < N; ++j) cout << to[j] << " "; cout << endl; cout << endl;
        }
        return cost;
    }
};