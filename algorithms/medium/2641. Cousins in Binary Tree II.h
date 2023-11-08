/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*>> layer;
        layer.push_back({nullptr, root});
        root->val = 0;

        while (!layer.empty()) {
            vector<pair<TreeNode*, TreeNode*>> next;
            int sum = 0;
            for (auto& l : layer) {
                auto p = l.first;
                auto n = l.second;

                if (n->left) {next.push_back({n, n->left}); sum += n->left->val;}
                if (n->right) {next.push_back({n, n->right}); sum += n->right->val;}
            }
            // cout << sum << endl;

            for (auto& l : layer) {
                auto p = l.first;
                auto n = l.second;

                int x = (n->left ? n->left->val : 0) + (n->right ? n->right->val : 0);
                if (n->left) n->left->val = sum - x;
                if (n->right) n->right->val = sum - x;
            }

            layer = next;
        }

        return root;
    }
};