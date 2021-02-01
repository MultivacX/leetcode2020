// 106. Construct Binary Tree from Inorder and Postorder Traversal

// Runtime: 4 ms, faster than 99.58% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.0
// Memory Usage: 17.1 MB, less than 61.11% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.

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
    unordered_map<int, int> _m;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            _m.insert({inorder[i], i});
        }
        return build(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& postorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie) {
        if (ps >= pe) return nullptr;
        
        auto root = new TreeNode(postorder[pe - 1]);
        
        int inorderRootIdx = _m[root->val];
        int leftNodeCnt = inorderRootIdx - is;
        
        root->left = build(postorder, ps, ps + leftNodeCnt, inorder, is, inorderRootIdx);
        root->right = build(postorder, ps + leftNodeCnt, pe - 1, inorder, inorderRootIdx + 1, ie);
        
        return root;
    }
};