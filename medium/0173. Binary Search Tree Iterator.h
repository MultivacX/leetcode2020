// 173. Binary Search Tree Iterator

// Runtime: 48 ms, faster than 96.65% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.3 MB, less than 76.09% of C++ online submissions for Binary Search Tree Iterator.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int ans = nodes.top()->val;
        auto root = nodes.top()->right;
        nodes.pop();
        while (root) {
            nodes.push(root);
            root = root->left;
        }
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }
    
    stack<TreeNode*> nodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */