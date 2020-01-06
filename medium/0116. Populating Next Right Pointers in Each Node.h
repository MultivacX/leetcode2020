// 116. Populating Next Right Pointers in Each Node

// Runtime: 24 ms, faster than 66.66% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 19.3 MB, less than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node.

// oh! it is a perfect binary tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        findParent(root, nullptr);
        findNext(root);
        return root;
    }
    
    void findParent(Node* node, Node* parent) {
        if (!node) return;
        node->next = parent;
        findParent(node->left, node);
        findParent(node->right, node);
    }
    
    void findNext(Node* node) {
        if (!node) return;
        auto parent = node->next;
        if (parent) {
            Node* np = nullptr;
            if (node == parent->left) {
                if (parent->right) {
                    node->next = parent->right;
                } else {
                    np = parent->next;
                }
            } else {
                np = parent->next;
            }
            
            while (np) {
                if (np->left) {
                    node->next = np->left;
                    break;
                } else if (np->right) {
                    node->next = np->right;
                    break;
                } else {
                    np = np->next;
                }
            }
            
            if (node->next == parent) {
                node->next = nullptr;
            }
        }
        findNext(node->right);
        findNext(node->left);
    }
};