// 1666. Change the Root of a Binary Tree
// https://leetcode.com/problems/change-the-root-of-a-binary-tree/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Change the Root of a Binary Tree.
// Memory Usage: 7.6 MB, less than 98.05% of C++ online submissions for Change the Root of a Binary Tree.
    
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
    Node* flip(Node* parent, Node* cur, Node* root, Node * leaf) {
        if (!cur) return nullptr;
        
        if (cur == leaf) {
            cur->parent = nullptr;
        } else {
            auto pre = flip(cur, cur->left, root, leaf);
            if (!pre) pre = flip(cur, cur->right, root, leaf);
            if (!pre) return nullptr;
            
            if (cur != root && cur->left) cur->right = cur->left;
        }
        
        if (cur != root) cur->left = parent;
        if (parent) parent->parent = cur;
        if (parent && parent->left == cur) parent->left = nullptr;
        else if (parent && parent->right == cur) parent->right = nullptr;
        return cur;
    }
    
    // unordered_set<Node*> nodes;
    // void debug(Node* root) {
    //     if (!root) return;
    //     nodes.insert(root);
    //     debug(root->left);
    //     debug(root->right);
    // }
    
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        // debug(root);
        flip(nullptr, root, root, leaf);
        // for (auto node : nodes) printf("%d: %d  %d\n", node->val, node->left ? node->left->val : -1, node->right ? node->right->val : -1);
        return leaf;
    }
};