// 117. Populating Next Right Pointers in Each Node II

// Runtime: 20 ms, faster than 63.39% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 19.8 MB, less than 100.00% of C++ online submissions for Populating Next Right Pointers in Each Node II.

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


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* pre_leftest = root;
        Node* leftest = root->left ? root->left : root->right;
        while (leftest) {
            Node* tmp_pre_leftest = leftest;
            
            Node* pre_lv = pre_leftest;
            Node* l = pre_lv->left; 
            Node* r = pre_lv->right;
            Node* cur_lv = leftest;
            while (pre_lv && cur_lv) {
                if (!l && !r) {
                    pre_lv = pre_lv->next;
                    if (pre_lv) l = pre_lv->left, r = pre_lv->right;
                } else if (l) {
                    if (cur_lv != l) {
                        cur_lv->next = l;
                        cur_lv = cur_lv->next;
                    }
                    l = nullptr;
                } else if (r) {
                    if (cur_lv != r) {
                        cur_lv->next = r;
                        cur_lv = cur_lv->next;
                    }
                    r = nullptr;
                }
            }
            
            pre_leftest = tmp_pre_leftest;
            leftest = nullptr;
            while (!leftest && tmp_pre_leftest) {
                if (tmp_pre_leftest->left) leftest = tmp_pre_leftest->left;
                else if (tmp_pre_leftest->right) leftest = tmp_pre_leftest->right;
                else tmp_pre_leftest = tmp_pre_leftest->next;
            }
        }
        return root;
    }
};