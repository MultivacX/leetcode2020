// 1273. Delete Tree Nodes
// https://leetcode.com/problems/delete-tree-nodes/

// Runtime: 128 ms, faster than 22.47% of C++ online submissions for Delete Tree Nodes.
// Memory Usage: 37.9 MB, less than 12.36% of C++ online submissions for Delete Tree Nodes.
    
class Solution {
    unordered_map<int, vector<int>> m;
    
    pair<int, int> postOrder(vector<int>& value, int node) {
        int sum = value[node];
        int cnt = 1;
        for (int c : m[node]) {
            auto p = postOrder(value, c);
            if (p.first != 0) {
                sum += p.first;
                cnt += p.second;
            }
        }
        if (sum == 0) return {0, 0};
        else return {sum, cnt};
    }
    
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for (int i = 1; i < nodes; ++i)
            m[parent[i]].push_back(i);
        auto p = postOrder(value, 0);
        return p.first != 0 ? p.second : 0;
    }
};