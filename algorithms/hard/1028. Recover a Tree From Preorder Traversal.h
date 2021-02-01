// 1028. Recover a Tree From Preorder Traversal

// Runtime: 24 ms, faster than 93.08% of C++ online submissions for Recover a Tree From Preorder Traversal.
// Memory Usage: 20.3 MB, less than 21.05% of C++ online submissions for Recover a Tree From Preorder Traversal.

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
    TreeNode* recoverFromPreorder(string S) {
        int idx = 0;
        return recover(S, idx, 0);
    }
    
    TreeNode* recover(const string& S, int& idx, int level) {
        if (idx >= S.length()) return nullptr;
        
        int j = idx;
        int count = 0;
        while (j < S.length() && S[j] == '-') {
            ++count;
            ++j;
        }
        if (count != level) return nullptr;
        
        idx = j;
        int val = 0;
        while (idx < S.length() && isdigit(S[idx])) {
            val = val * 10 + S[idx] - '0';
            ++idx;
        }
        auto root = new TreeNode(val);
        root->left = recover(S, idx, level + 1);
        root->right = recover(S, idx, level + 1);
        return root;
    }
};