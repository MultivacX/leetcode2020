// 545. Boundary of Binary Tree
// https://leetcode.com/problems/boundary-of-binary-tree/

// Runtime: 16 ms, faster than 39.25% of C++ online submissions for Boundary of Binary Tree.
// Memory Usage: 21.7 MB, less than 8.60% of C++ online submissions for Boundary of Binary Tree.

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
    bool isLeave(TreeNode* node) {
        return !node->left && !node->right;
    }
    
    void inorder(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        
        inorder(root->left, leaves);
        if (isLeave(root)) 
            leaves.push_back(root->val);
        inorder(root->right, leaves);
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        
        vector<int> left, right, leaves;
        
        if (!isLeave(root)) left.push_back(root->val);
        
        auto node = root->left;
        while (node && !isLeave(node)) {
            left.push_back(node->val);
            node = node->left ? node->left : node->right;
        }
        
        node = root->right;
        while (node && !isLeave(node)) {
            right.push_back(node->val);
            node = node->right ? node->right : node->left;
        }
        
        inorder(root, leaves);
        
        // for (int i : left) cout << i << " "; cout << endl;
        // for (int i : leaves) cout << i << " "; cout << endl;
        // for (int i : right) cout << i << " "; cout << endl;
        
        left.insert(left.end(), leaves.begin(), leaves.end());
        reverse(right.begin(), right.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};