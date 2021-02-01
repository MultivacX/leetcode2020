// 1086. High Five
// https://leetcode.com/problems/high-five/

// Runtime: 28 ms, faster than 62.00% of C++ online submissions for High Five.
// Memory Usage: 11 MB, less than 62.77% of C++ online submissions for High Five.
    
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (auto& v : items) {
            m[v[0]].push(v[1]);
            if (m[v[0]].size() > 5)
                m[v[0]].pop();
        }
        vector<vector<int>> ans;
        for (auto it : m) {
            int sum = 0;
            while (!it.second.empty()) {
                sum += it.second.top();
                it.second.pop();
            }
            ans.push_back({it.first, sum / 5});
        }
        return ans;
    }
};