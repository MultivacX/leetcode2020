// 1615. Maximal Network Rank
// https://leetcode.com/problems/maximal-network-rank/

// Runtime: 192 ms, faster than 72.67% of C++ online submissions for Maximal Network Rank.
// Memory Usage: 39.3 MB, less than 5.23% of C++ online submissions for Maximal Network Rank.

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> m(n);
        for (const auto& r : roads) {
            m[r[0]].insert(r[1]);
            m[r[1]].insert(r[0]);
        }
        int rank = 0;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int r = m[i].size() + m[j].size() + (m[i].count(j) ? -1 : 0);
                rank = max(rank, r);
            }
        }
        return rank;
    }
};