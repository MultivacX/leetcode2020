// 1586. Binary Search Tree Iterator II
// https://leetcode.com/problems/binary-search-tree-iterator-ii/

// Runtime: 480 ms, faster than 94.52% of C++ online submissions for Binary Search Tree Iterator II.
// Memory Usage: 150.4 MB, less than 65.75% of C++ online submissions for Binary Search Tree Iterator II.
    
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
class BSTIterator {
    stack<TreeNode*> s;
    vector<int> v;
    int i = -1;
    
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    bool hasNext() {
        return !s.empty() || i + 1 < v.size();
    }
    
    int next() {
        ++i;
        if (i >= v.size()) {
            auto root = s.top(); s.pop();
            v.push_back(root->val);
            root = root->right;
            while (root) {
                s.push(root);
                root = root->left;
            }
        }
        return v[i];
    }
    
    bool hasPrev() {
        return i > 0 && !v.empty();
    }
    
    int prev() {
        return v[--i];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */