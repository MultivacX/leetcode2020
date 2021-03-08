// 589. N-ary Tree Preorder Traversal

// Runtime: 88 ms, faster than 60.82% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 56.7 MB, less than 10.53% of C++ online submissions for N-ary Tree Preorder Traversal.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
    
    void f(Node* root, vector<int>& ans) {
        if (!root) return;
        
        ans.push_back(root->val);
        for (auto child : root->children) {
            f(child, ans);
        }
    }
};


class Solution {
    vector<int> ans;
    
    void helper(Node* root) {
        if (!root) return;
        ans.push_back(root->val);
        for (auto node : root->children)
            helper(node);
    }
    
public:
    vector<int> preorder(Node* root) {
        helper(root);
        return ans;
    }
};