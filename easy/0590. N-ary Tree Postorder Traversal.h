// 590. N-ary Tree Postorder Traversal

// Runtime: 48 ms, faster than 27.55% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for N-ary Tree Postorder Traversal.

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
	// TODO: iteratively

    vector<int> postorder(Node* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
    
    void f(Node* root, vector<int>& ans) {
        if (!root) return;
        for (auto node : root->children) {
            f(node, ans);
        }
        ans.push_back(root->val);
    }
};