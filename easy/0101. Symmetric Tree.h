// 101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Runtime: 4 ms, faster than 84.24% of C++ online submissions for Symmetric Tree.
// Memory Usage: 14.6 MB, less than 100.00% of C++ online submissions for Symmetric Tree.
// recursively 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l && r) return false;
        if (l && !r) return false;
        if (l->val != r->val) return false;
        return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
    }
};

// Runtime: 4 ms, faster than 92.25% of C++ online submissions for Symmetric Tree.
// Memory Usage: 17.6 MB, less than 5.11% of C++ online submissions for Symmetric Tree.
// iteratively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> nodes{root->left, root->right};
        
        while (!nodes.empty()) {
            deque<TreeNode*> next;
            while (!nodes.empty()) {
                auto l = nodes.front();
                nodes.pop_front();
                auto r = nodes.back();
                nodes.pop_back();
                // cout << (l ? to_string(l->val) : "*") << "<>" << (r ? to_string(r->val) : "*") << " ";

                if (l && r && l->val == r->val) {
                    if (l->left && r->right) {
                        next.push_front(l->left);
                        next.push_back(r->right);
                    } else if (!l->left && !r->right) {
                        //
                    } else {
                        return false;    
                    }

                    if (l->right && r->left) {
                        next.push_front(l->right);
                        next.push_back(r->left);
                    } else if (!l->right && !r->left) {
                        //
                    } else {
                        return false;
                    }
                } else if (!l && !r) {
                    //
                } else {
                    return false;
                }
            }
            // cout << endl;
            swap(nodes, next);
        }
        return true;
    }
};