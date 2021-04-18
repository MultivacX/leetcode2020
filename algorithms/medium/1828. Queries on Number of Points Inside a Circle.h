// 1828. Queries on Number of Points Inside a Circle
// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

// Runtime: 92 ms, faster than 77.78% of C++ online submissions for Queries on Number of Points Inside a Circle.
// Memory Usage: 16.7 MB, less than 55.56% of C++ online submissions for Queries on Number of Points Inside a Circle.
    
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        sort(begin(points), end(points));
        for (const auto& q : queries) {
            vector<int> l{q[0] - q[2], q[1] - q[2]};
            auto it = lower_bound(begin(points), end(points), l);
            int k = 0;
            while (it != end(points)) {
                int x = (*it)[0], y = (*it)[1];
                if (x > q[0] + q[2]) break;
                int d = (x - q[0]) * (x - q[0]) + (y - q[1]) * (y - q[1]);
                if (d <= q[2] * q[2]) ++k;
                ++it;
            }
            ans.push_back(k);
        }
        return ans;
    }
};