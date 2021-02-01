// 1506. Find Root of N-Ary Tree
// https://leetcode.com/problems/find-root-of-n-ary-tree/

// Runtime: 156 ms, faster than 85.82% of C++ online submissions for Find Root of N-Ary Tree.
// Memory Usage: 252.5 MB, less than 96.45% of C++ online submissions for Find Root of N-Ary Tree.

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

// wrong assumption: all val >= 0

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        for (auto node : tree) 
            for (auto c : node->children)
                if (c->val >= 0)
                    c->val = -(c->val + 1);
        
        Node* root = nullptr;
        for (auto node : tree) 
            if (node->val >= 0) root = node;
            else node->val = -(node->val + 1);
        return root;
    }
};