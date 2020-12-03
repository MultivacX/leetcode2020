// 1490. Clone N-ary Tree
// https://leetcode.com/problems/clone-n-ary-tree/

// Runtime: 84 ms, faster than 46.81% of C++ online submissions for Clone N-ary Tree.
// Memory Usage: 175.3 MB, less than 57.09% of C++ online submissions for Clone N-ary Tree.
    
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
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        auto root0 = new Node(root->val);
        for (Node* c : root->children)
            root0->children.push_back(cloneTree(c));
        return root0;
    }
};