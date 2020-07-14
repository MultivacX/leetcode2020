// 1499. Max Value of Equation
// https://leetcode.com/problems/max-value-of-equation/

// Runtime: 936 ms, faster than 35.93% of C++ online submissions for Max Value of Equation.
// Memory Usage: 90.1 MB, less than 100.00% of C++ online submissions for Max Value of Equation.

// Time Complexity: O(N).
// Space Complexity: O(N).

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // yi + yj + |xi - xj|, if j > i, means xj > xi, then (yj + xj) + (yi - xi)

        int ans = INT_MIN;
        deque<int> q;
        q.push_front(0);
        for (int j = 1; j < points.size(); ++j) {
            int xj = points[j][0];
            while (!q.empty() && xj - points[q.front()][0]/*xi*/ > k) q.pop_front();
            while (!q.empty() && xj - points[q.back()][0]/*xi*/ > k) q.pop_back();
            
            if (!q.empty()) {
                int yj = points[j][1];
                int xi = points[q.back()][0];
                int yi = points[q.back()][1];
                ans = max(ans, yi + yj + xj - xi);
                while (!q.empty() && points[q.front()][1]/*yi*/ - points[q.front()][0]/*xi*/ <= yj - xj) q.pop_front();
            }
            q.push_front(j);
        }
        return ans;
    }
};