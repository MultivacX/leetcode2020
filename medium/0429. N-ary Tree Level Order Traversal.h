// 429. N-ary Tree Level Order Traversal

// Runtime: 72 ms, faster than 44.22% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 57.5 MB, less than 5.55% of C++ online submissions for N-ary Tree Level Order Traversal.

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
	
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        f(root, &ans, 1);
        return ans;
    }
    
    void f(const Node* root, vector<vector<int>>* ans, int level) {
        if (!root) return;
        if ((*ans).size() < level) (*ans).emplace_back(vector<int>{root->val});
        else (*ans)[level - 1].emplace_back(root->val);
        for (const Node* node : root->children) {
            f(node, ans, level + 1);
        }
    }
};