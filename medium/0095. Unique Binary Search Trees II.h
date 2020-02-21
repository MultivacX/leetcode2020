// 95. Unique Binary Search Trees II

// Runtime: 24 ms, faster than 66.82% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 19 MB, less than 13.89% of C++ online submissions for Unique Binary Search Trees II.

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
    using M = unordered_map<int, vector<TreeNode*>>;
    
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return {};
        vector<M> m(n + 1);
        m[0].insert({0, {nullptr}});
        return vector<TreeNode*>(gen(1, n, m));
    }

    vector<TreeNode*>& gen(int min, int max, vector<M>& m) {
        if (min > max) return m[0][0];

        auto it = m[min].find(max);
        if (it != m[min].end())
            return m[min][max];

        vector<TreeNode*> ans;
        for (int i = min; i <= max; ++i) {
            auto l = gen(min, i - 1, m);
            auto r = gen(i + 1, max, m);
            for (auto lc : l) {
                for (auto rc : r) {
                    auto root = new TreeNode(i);
                    root->left = clone(lc);
                    root->right = clone(rc);
                    ans.push_back(root);
                }
            }
        }
        m[min].insert({ max, ans });
        return m[min][max];
    }

    TreeNode* clone(TreeNode* root) {
        if (!root) return root;
        auto new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);
        return new_root;
    }
};