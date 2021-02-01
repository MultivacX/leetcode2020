// 536. Construct Binary Tree from String
// https://leetcode.com/problems/construct-binary-tree-from-string/

// Runtime: 44 ms, faster than 71.46% of C++ online submissions for Construct Binary Tree from String.
// Memory Usage: 26 MB, less than 95.96% of C++ online submissions for Construct Binary Tree from String.
    
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
    TreeNode* str2tree(const string& s, int& i) {
        TreeNode* node = nullptr;
        while (i < s.length()) {
            if (s[i] == '(') {
                ++i;
                auto child = str2tree(s, i);
                if (!node->left) node->left = child;
                else node->right = child;
            } else if (s[i] == ')') {
                ++i;
                return node;
            } else {
                int val = 0;
                int sig = 1;
                while (i < s.length() && (s[i] == '-' || isdigit(s[i]))) {
                    if (s[i] == '-') sig = -1;
                    else val = val * 10 + (s[i] - '0') * sig;
                    ++i;
                }
                node = new TreeNode(val);
            }
        }
        return node;
    }
    
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return str2tree(s, i);
    }
};