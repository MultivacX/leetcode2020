// 987. Vertical Order Traversal of a Binary Tree

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
// Memory Usage: 14.7 MB, less than 22.22% of C++ online submissions for Vertical Order Traversal of a Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        
        map<int, vector<pair<int, int>>> m;
        f(root, 0, 0, m);
        vector<vector<int>> ans;
        for (auto it : m) {
            sort(it.second.begin(), it.second.end(), [](pair<int, int>& a, pair<int, int>& b){ return a.first < b.first || (a.first == b.first && a.second <= b.second); });
            vector<int> v;
            for (auto& j : it.second) {
                v.push_back(j.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
    
    void f(TreeNode* root, int x, int y, map<int, vector<pair<int, int>>>& m) {
        if (!root) return;
        m[x].push_back({y, root->val});
        f(root->left, x - 1, y + 1, m);
        f(root->right, x + 1, y + 1, m);
    }
};