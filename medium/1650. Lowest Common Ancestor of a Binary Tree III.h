// 1650. Lowest Common Ancestor of a Binary Tree III
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

// Runtime: 24 ms, faster than 31.23% of C++ online submissions for Lowest Common Ancestor of a Binary Tree III.
// Memory Usage: 11.9 MB, less than 14.29% of C++ online submissions for Lowest Common Ancestor of a Binary Tree III.
    
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> nodes;
        while (p) {
            nodes.insert(p);
            p = p->parent;
        }
        while (q) {
            if (!nodes.insert(q).second) return q;
            q = q->parent;
        }
        return nullptr;
    }
};