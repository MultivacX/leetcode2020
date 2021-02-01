// 510. Inorder Successor in BST II
// https://leetcode.com/problems/inorder-successor-in-bst-ii/

// Runtime: 20 ms, faster than 96.23% of C++ online submissions for Inorder Successor in BST II.
// Memory Usage: 12 MB, less than 12.55% of C++ online submissions for Inorder Successor in BST II.
    
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
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        
        auto p = node->right;
        while (p && p->left) p = p->left;
        if (p) return p;
        
        p = node->parent;
        auto q = node;
        while (p) {
            if (p->left == q) break;
            q = p;
            p = p->parent;
        }
        return p;
    }
};