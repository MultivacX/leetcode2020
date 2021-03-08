// 429. N-ary Tree Level Order Traversal

// Runtime: 40 ms, faster than 92.82% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 11.8 MB, less than 56.98% of C++ online submissions for N-ary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vals;
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                vals.push_back(cur->val);
                for (auto* c : cur->children)
                    q.push(c);
            }
            ans.push_back(vals);
        }
        return ans;
    }
};

// Runtime: 72 ms, faster than 44.22% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 57.5 MB, less than 5.55% of C++ online submissions for N-ary Tree Level Order Traversal.
/*class Solution {
public:
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
};*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back({});
            int n = q.size();
            while (n-- > 0) {
                Node* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                for (auto child : node->children)
                    q.push(child);
            }
        }
        return ans;
    }
};