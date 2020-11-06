// 1128. Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

// Runtime: 96 ms, faster than 81.83% of C++ online submissions for Number of Equivalent Domino Pairs.
// Memory Usage: 22.4 MB, less than 29.20% of C++ online submissions for Number of Equivalent Domino Pairs.

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        for (const auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            ++m[a * 50000 + b];
        }
        int ans = 0;
        for (auto it : m) ans += it.second * (it.second - 1) / 2;
        return ans;
    }
};