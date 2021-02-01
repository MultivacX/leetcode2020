// 830. Positions of Large Groups
// https://leetcode.com/problems/positions-of-large-groups/

// Runtime: 4 ms, faster than 89.99% of C++ online submissions for Positions of Large Groups.
// Memory Usage: 7.8 MB, less than 71.33% of C++ online submissions for Positions of Large Groups.

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for (int i = 1, l = 1; i < s.length(); ++i) {
            if (s[i] != s[i - 1]) {
                if (l >= 3) ans.push_back({i - l, i - 1});
                l = 0;
            }
            ++l;
            if (l >= 3 && i + 1 == s.length()) 
                ans.push_back({i - l + 1, i});
        }
        return ans;
    }
};