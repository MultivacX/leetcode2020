// 1519. Number of Nodes in the Sub-Tree With the Same Label
// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

// Runtime: 1072 ms, faster than 34.99% of C++ online submissions for Number of Nodes in the Sub-Tree With the Same Label.
// Memory Usage: 255 MB, less than 5.30% of C++ online submissions for Number of Nodes in the Sub-Tree With the Same Label.

class Solution {
    unordered_map<int, unordered_set<int>> tree;
    
    array<int, 26> postOrder(int node, vector<int>& ans, const string& labels) {
        // visited
        ans[node] += 1;
        
        array<int, 26> cnt{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (auto child : tree[node]) {
            // visited
            if (ans[child] > 0) continue;
            
            auto c = postOrder(child, ans, labels);
            for (int i = 0; i < 26; ++i) cnt[i] += c[i];
        }
        int i = labels[node] - 'a';
        ans[node] += cnt[i];
        cnt[i] += 1;
        return cnt;
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for (const auto& e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        vector<int> ans(n, 0);
        postOrder(0, ans, labels);
        return ans;
    }
};