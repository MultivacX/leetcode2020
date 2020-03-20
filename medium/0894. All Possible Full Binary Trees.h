// 894. All Possible Full Binary Trees

// Runtime: 296 ms, faster than 6.05% of C++ online submissions for All Possible Full Binary Trees.
// Memory Usage: 63 MB, less than 7.14% of C++ online submissions for All Possible Full Binary Trees.

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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        
        vector<TreeNode*> v;
        for (int i = 1; i < N; i += 2) {
            auto lv = allPossibleFBT(i);
            auto rv = allPossibleFBT(N - 1 - i);
            for (auto l : lv) {
                for (auto r : rv) {
                    auto root = new TreeNode(0);
                    root->left = cloneTree(l);
                    root->right = cloneTree(r);
                    v.push_back(root);
                }    
            }
            for (auto l : lv) deleteTree(l);
            for (auto r : rv) deleteTree(r);
        }
        return v;
    }
    
    TreeNode* cloneTree(TreeNode* root) {
        if (!root) return nullptr;
        auto _root = new TreeNode(0);
        _root->left = cloneTree(root->left);
        _root->right = cloneTree(root->right);
        return _root;    
    }
    
    void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};