// 1612. Check If Two Expression Trees are Equivalent
// https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/

// Runtime: 188 ms, faster than 49.13% of C++ online submissions for Check If Two Expression Trees are Equivalent.
// Memory Usage: 44.8 MB, less than 44.76% of C++ online submissions for Check If Two Expression Trees are Equivalent.

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<char, int> m;
    
    void count(Node* node, int v) {
        if (!node) return;
        if (node->val != '+') m[node->val] += v;
        count(node->left, v);
        count(node->right, v);
    }
    
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        count(root1, 1);
        count(root2, -1);
        for (auto it : m) if (it.second) return false;
        return true;
    }
};