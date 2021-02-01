// 1485. Clone Binary Tree With Random Pointer
// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/

// Runtime: 416 ms, faster than 74.88% of C++ online submissions for Clone Binary Tree With Random Pointer.
// Memory Usage: 76.4 MB, less than 45.50% of C++ online submissions for Clone Binary Tree With Random Pointer.
    
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> m;
    
    NodeCopy* create(Node* root) {
        if (!root) return nullptr;
        NodeCopy* node = new NodeCopy(root->val);
        m.insert({root, node});
        node->left = create(root->left);
        node->right = create(root->right);
        return node;
    }
    
    void random(Node* root) {
        if (!root) return;
        m[root]->random = m[root->random];
        random(root->left);
        random(root->right);
    }
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* rootCopy = create(root);
        random(root);
        return rootCopy;
    }
};