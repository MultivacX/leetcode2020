// 1109. Corporate Flight Bookings
// https://leetcode.com/problems/corporate-flight-bookings

// Runtime: 388 ms, faster than 91.90% of C++ online submissions for Corporate Flight Bookings.
// Memory Usage: 68 MB, less than 61.04% of C++ online submissions for Corporate Flight Bookings.

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (const auto& b : bookings) {
            int i = b[0];
            int j = b[1];
            int k = b[2];
            
            ans[i - 1] += k;
            if (j < n) ans[j] -= k;
        }
        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};