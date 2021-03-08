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
	// iteratively
    /*vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            for (auto* c : cur->children)
                s.push(c);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }*/

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


class Solution {
    vector<int> ans;
    
    void helper(Node* root) {
        if (!root) return;
        for (auto node : root->children)
            helper(node);
        ans.push_back(root->val);
    }
    
public:
    vector<int> postorder(Node* root) {
        helper(root);
        return ans;
    }
};