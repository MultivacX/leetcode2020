// 356. Line Reflection
// https://leetcode.com/problems/line-reflection/

// Runtime: 60 ms, faster than 68.31% of C++ online submissions for Line Reflection.
// Memory Usage: 20 MB, less than 12.68% of C++ online submissions for Line Reflection.
    
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int l = INT_MAX, r = INT_MIN;
        unordered_map<int, unordered_set<int>> x2y;
        for (auto& p : points) {
            l = min(l, p[0]);
            r = max(r, p[0]);
            x2y[p[0] * 2].insert(p[1]);
        }
        int xt = r + l;
        while (!x2y.empty()) {
            auto it = x2y.begin();
            int x0 = it->first;
            if (x0 == xt) {
                x2y.erase(x0);
                continue;
            }
            int x1 = xt * 2 - x0;
            if (x2y.count(x1) == 0 || x2y[x1] != x2y[x0])
                return false;
            x2y.erase(x0);
            x2y.erase(x1);
        }
        return x2y.empty();
    }
};