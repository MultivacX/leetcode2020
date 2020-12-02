// 426. Convert Binary Search Tree to Sorted Doubly Linked List
// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

// Runtime: 8 ms, faster than 76.17% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
// Memory Usage: 8.2 MB, less than 13.51% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
    
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* head = nullptr;
    Node* pre = nullptr;
    
    void inorder(Node* root) {
        if (!root) return;
        
        inorder(root->left);
        
        if (!head) head = root;
        if (pre) {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        
        inorder(root->right);
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        inorder(root);
        if (head) {
            pre->right = head;
            head->left = pre;
        }
        return head;
    }
};