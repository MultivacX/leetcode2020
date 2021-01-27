// 1516. Move Sub-Tree of N-Ary Tree
// https://leetcode.com/problems/move-sub-tree-of-n-ary-tree/

// Runtime: 48 ms, faster than 92.00% of C++ online submissions for Move Sub-Tree of N-Ary Tree.
// Memory Usage: 29.3 MB, less than 60.00% of C++ online submissions for Move Sub-Tree of N-Ary Tree.
    
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
    bool getPath(Node* root, Node* target, vector<Node*>& path) {
        if (!root) return false;
        
        if (root == target) return true;
        
        path.push_back(root);
        for (auto p : root->children) 
            if (getPath(p, target, path))
                return true;
        path.pop_back();
        
        return false;
    }
    
    void replaceFromParent(Node* parent, Node* oldNode, Node* newNode) {
        auto it = find(begin(parent->children), end(parent->children), oldNode);
        *it = newNode;
    }
    
    void removeFromParent(Node* parent, Node* node) {
        auto it = find(begin(parent->children), end(parent->children), node);
        parent->children.erase(it);
    }
    
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        // p is already a direct child of q
        if (find(begin(q->children), end(q->children), p) != q->children.end())
            return root;
        
        vector<Node*> path_p, path_q;
        getPath(root, p, path_p);
        getPath(root, q, path_q);
        // for (auto node : path_p) cout << node->val << " -> "; 
        // cout << "[" << p->val << "]" << endl;
        // for (auto node : path_q) cout << node->val << " -> "; 
        // cout << "[" << q->val << "]" << endl << endl;
        
        auto it = find(begin(path_q), end(path_q), p);
        if (it != path_q.end()) {
            // 1. Node q is in the sub-tree of node p.
            removeFromParent(path_q.back(), q);
            if (path_p.empty()) {
                q->children.push_back(p);
                return q;
            } else {
                replaceFromParent(path_p.back(), p, q);
                q->children.push_back(p);
                return root;
            }
        } else {
            // 2. Node p is in the sub-tree of node q.
            // 3. Neither node p is in the sub-tree of node q nor node q is in the sub-tree of node p.
            removeFromParent(path_p.back(), p);
            q->children.push_back(p);
            return root;
        }
    }
};