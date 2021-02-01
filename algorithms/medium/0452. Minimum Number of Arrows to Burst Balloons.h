// 452. Minimum Number of Arrows to Burst Balloons

// Runtime: 288 ms, faster than 44.55% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
// Memory Usage: 35 MB, less than 20.00% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.

// Time Complexity: O(N * lgN).
// Space Complexity: O(1).

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int N = points.size();
        if (N <= 1) return N;
        
        sort(begin(points), end(points), [](const vector<int>& l, const vector<int>& r){ 
            return l[1] < r[1] || (l[0] < r[0] && l[1] == r[1]); 
        });
        
        int x = points[0][1];
        int ans = 1;
        for (int i = 1; i < N; ++i) {
            if (points[i][0] <= x) continue;
            x = points[i][1];
            ++ans;
        }
        return ans;
    }
};