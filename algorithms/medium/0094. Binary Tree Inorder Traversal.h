// 94. Binary Tree Inorder Traversal

// Runtime: 4 ms, faster than 58.73% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.2 MB, less than 89.00% of C++ online submissions for Binary Tree Inorder Traversal.

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        set<TreeNode*> visited;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            if (node->left && visited.count(node->left) == 0) {
                s.push(node->left);
                continue;
            } 
            
            s.pop();
            visited.insert(node);
            ans.push_back(node->val);
            if (node->right) s.push(node->right);
        }
        return ans;
    }
};


class Solution {
    vector<int> ans;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        stack<TreeNode*> s;
        auto p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};