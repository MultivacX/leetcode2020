// 1305. All Elements in Two Binary Search Trees

// Runtime: 284 ms, faster than 50.02% of C++ online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 60.1 MB, less than 100.00% of C++ online submissions for All Elements in Two Binary Search Trees.

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<int> s1;
        inorder1(root1, s1);
        
        vector<int> ans;
        inorder2(root2, s1, ans);
        
        while (!s1.empty()) {
            ans.push_back(s1.top());
            s1.pop();
        }
        
        return ans;
    }
    
    void inorder1(TreeNode* root1, stack<int>& s1) {
        if (!root1) return;
        
        inorder1(root1->right, s1);
        s1.push(root1->val);
        inorder1(root1->left, s1);
    }
    
    void inorder2(TreeNode* root2, stack<int>& s1, vector<int>& ans) {
        if (!root2) return;
        
        inorder2(root2->left, s1, ans);
        while (!s1.empty() && s1.top() <= root2->val) {
            ans.push_back(s1.top());
            s1.pop();
        }
        ans.push_back(root2->val);
        inorder2(root2->right, s1, ans);
    }
};