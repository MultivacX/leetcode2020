// 431. Encode N-ary Tree to Binary Tree
// https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/

// Runtime: 84 ms, faster than 26.74% of C++ online submissions for Encode N-ary Tree to Binary Tree.
// Memory Usage: 173.3 MB, less than 100.00% of C++ online submissions for Encode N-ary Tree to Binary Tree.
    
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        auto tn = new TreeNode(root->val);
        TreeNode* pre = nullptr;
        for (int i = root->children.size() - 1; i >= 0; --i) {
            auto cur = encode(root->children[i]);
            cur->right = pre;
            pre = cur;
            if (i == 0) tn->left = cur;
        }
        return tn;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        auto n = new Node(root->val);
        auto child = root->left;
        while (child) {
            n->children.push_back(decode(child));
            child = child->right;
        }
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));