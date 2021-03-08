// 559. Maximum Depth of N-ary Tree

// Runtime: 60 ms, faster than 48.51% of C++ online submissions for Maximum Depth of N-ary Tree.
// Memory Usage: 55.3 MB, less than 5.00% of C++ online submissions for Maximum Depth of N-ary Tree.

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
    int maxDepth(Node* root) {
        if (!root) return 0;
        int d = 0;
        for (auto c : root->children)
            d = max(d, maxDepth(c));
        return 1 + d;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int ans = 0;
        for (auto child : root->children)
            ans = max(ans, maxDepth(child));
        return ans + 1;
    }
};