// 105. Construct Binary Tree from Preorder and Inorder Traversal

// Runtime: 16 ms, faster than 79.77% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 16.5 MB, less than 95.24% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie) {
        if (ps >= pe) return nullptr;
        
        auto root = new TreeNode(preorder[ps]);
        
        int inorderRootIdx = -1;
        for (int i = is; i < ie; ++i) {
            if (inorder[i] == root->val) {
                inorderRootIdx = i;
                break;
            }
        }
        
        int leftNodeCnt = inorderRootIdx - is;
        
        root->left = build(preorder, ps + 1, ps + 1 + leftNodeCnt, inorder, is, inorderRootIdx);
        root->right = build(preorder, ps + 1 + leftNodeCnt, pe, inorder, inorderRootIdx + 1, ie);
        
        return root;
    }
};


class Solution {
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int i, int j, int x, int y) {
        if (i > j) return nullptr;
        
        // [x, m-1] m [m+1, y]
        int m = find(begin(inorder) + x, begin(inorder) + y + 1, preorder[i]) - begin(inorder);
        
        auto root = new TreeNode(preorder[i]);
        root->left = buildTree(preorder, inorder, i + 1, i + m - x, x, m - 1);
        root->right = buildTree(preorder, inorder, i + m - x + 1, j, m + 1, y);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
};