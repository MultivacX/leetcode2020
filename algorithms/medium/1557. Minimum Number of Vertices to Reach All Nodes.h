// 1557. Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// Runtime: 608 ms, faster than 74.53% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
// Memory Usage: 107 MB, less than 5.12% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n, 0);
        for (auto e : edges) ++nodes[e[1]];
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (nodes[i] == 0)
                ans.push_back(i);
        return ans;
    }
};