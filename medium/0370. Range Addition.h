// 370. Range Addition
// https://leetcode.com/problems/range-addition/

// Runtime: 48 ms, faster than 85.38% of C++ online submissions for Range Addition.
// Memory Usage: 16.8 MB, less than 82.31% of C++ online submissions for Range Addition.
    
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (const auto& u : updates) {
            ans[u[0]] += u[2];
            if (u[1] + 1 < length)
                ans[u[1] + 1] -= u[2];
        }
        for (int i = 1; i < length; ++i)
            ans[i] += ans[i - 1];
        return ans;
    }
};