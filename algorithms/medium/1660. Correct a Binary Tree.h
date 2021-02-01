// 1660. Correct a Binary Tree
// https://leetcode.com/problems/correct-a-binary-tree/

// Runtime: 196 ms, faster than 54.72% of C++ online submissions for Correct a Binary Tree.
// Memory Usage: 80.8 MB, less than 44.15% of C++ online submissions for Correct a Binary Tree.
    
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        unordered_set<TreeNode*> nodes{root};
        while (!q.empty()) {
            int size = q.size();
            unordered_set<TreeNode*> tmp;
            while (size-- > 0) {
                auto parent = q.front().first;
                auto node = q.front().second;
                q.pop();
                if (node->left) {
                    q.push({node, node->left});
                    tmp.insert(node->left);
                }
                if (node->right) {
                    if (nodes.count(node->right)) {
                        if (parent->left == node) parent->left = nullptr;
                        else if (parent->right == node) parent->right = nullptr;
                        return root;
                    }
                    q.push({node, node->right});
                    tmp.insert(node->right);
                }
            }
            nodes = tmp;
        }
        return root;
    }
};