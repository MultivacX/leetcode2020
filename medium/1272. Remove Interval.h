// 1272. Remove Interval
// https://leetcode.com/problems/remove-interval/

// Runtime: 256 ms, faster than 5.20% of C++ online submissions for Remove Interval.
// Memory Usage: 49.3 MB, less than 5.31% of C++ online submissions for Remove Interval.
    
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        map<int, int> m;
        for (auto& i : intervals) ++m[i[0]], --m[i[1]];
        --m[toBeRemoved[0]], ++m[toBeRemoved[1]];
        vector<vector<int>> ans;
        int v = 0;
        int s = INT_MAX;
        for (auto it : m) {
            v += it.second;
            if (v <= 0) {
                if (s != INT_MAX) {
                    ans.push_back({s, it.first});
                }
                s = INT_MAX;
            } else if (v > 0) {
                if (s == INT_MAX) {
                    s = it.first;
                }
            }
        }
        return ans;
    }
};