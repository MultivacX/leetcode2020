// 1791. Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/

// Runtime: 176 ms, faster than 100.00% of C++ online submissions for Find Center of Star Graph.
// Memory Usage: 68.3 MB, less than 100.00% of C++ online submissions for Find Center of Star Graph.
    
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        vector<int> neighbors(n + 1);
        for (const auto& e : edges)
            ++neighbors[e[0]],
            ++neighbors[e[1]];
        for (int i = 1; i <= n; ++i)
            if (neighbors[i] == n - 1)
                return i;
        return 0;
    }
};