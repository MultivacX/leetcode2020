// 1817. Finding the Users Active Minutes
// https://leetcode.com/problems/finding-the-users-active-minutes/

// Runtime: 224 ms, faster than 75.00% of C++ online submissions for Finding the Users Active Minutes.
// Memory Usage: 85.4 MB, less than 25.00% of C++ online submissions for Finding the Users Active Minutes.
    
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        for (const auto& l : logs)
            m[l[0]].insert(l[1]);
        
        vector<int> ans(k);
        for (const auto& [_, uam] : m)
            ++ans[uam.size() - 1];
        return ans;
    }
};