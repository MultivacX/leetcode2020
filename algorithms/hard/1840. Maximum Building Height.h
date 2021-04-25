// 1840. Maximum Building Height
// https://leetcode.com/problems/maximum-building-height/

// Runtime: 632 ms, faster than 41.67% of C++ online submissions for Maximum Building Height.
// Memory Usage: 102.3 MB, less than 50.00% of C++ online submissions for Maximum Building Height.
    
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(begin(restrictions), end(restrictions));
        if (restrictions.back()[0] != n) 
            restrictions.push_back({n, n - 1});
        
        int ans = 0;
        for (int i = 0; i + 1 < restrictions.size(); ++i) {
            int l = restrictions[i][0], lh = restrictions[i][1];
            int r = restrictions[i + 1][0], &rh = restrictions[i + 1][1];
            if (rh > lh + r - l) rh = lh + r - l;
        }
        
        for (int i = restrictions.size() - 1; i > 0; --i) {
            int l = restrictions[i - 1][0], &lh = restrictions[i - 1][1];
            int r = restrictions[i][0], rh = restrictions[i][1];
            if (lh > rh + r - l) lh = rh + r - l;
        }
        
        for (int i = 0; i + 1 < restrictions.size(); ++i) {
            int l = restrictions[i][0], lh = restrictions[i][1];
            int r = restrictions[i + 1][0], rh = restrictions[i + 1][1];
            ans = max(ans, max(lh, rh));
            if (abs(lh - rh) != r - l) {
                int t = r - (l + abs(lh - rh)) - 1;
                ans = max(ans, max(lh, rh) + (t + 1) / 2);
            }
        }
        return ans;
    }
};