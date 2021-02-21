// 103. Binary Tree Zigzag Level Order Traversal

// Runtime: 4 ms, faster than 86.30% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 13.4 MB, less than 97.67% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        vector<TreeNode*> level{root};
        bool startFromLeft = true;
        while (!level.empty()) {
            ans.push_back({});
            vector<TreeNode*> nextLevel;
            for (auto node : level) {
                ans.back().push_back(node->val);
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            if (!startFromLeft) {
                reverse(ans.back().begin(), ans.back().end());
            }
            startFromLeft = !startFromLeft;
            swap(level, nextLevel);
        }
        return ans;
    }

	// WRONG
    /*vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        f(root, ans, 1, true);
        // remove startFromLeft
        // &
        // use reverse
        return ans;
    }
    
    void f(TreeNode* root, vector<vector<int>>& ans, int level, bool startFromLeft) {
        if (!root) return;
        
        if (ans.size() < level) ans.push_back({root->val});
        else ans[level - 1].push_back(root->val);
        
        if (startFromLeft) {
            f(root->right, ans, level + 1, !startFromLeft);
            f(root->left, ans, level + 1, !startFromLeft);
        } else {
            f(root->left, ans, level + 1, !startFromLeft);
            f(root->right, ans, level + 1, !startFromLeft);
        }
    }*/
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        bool r = false;
        vector<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            ans.push_back({});
            for (int i = 0; i < q.size(); ++i) {
                int j = r ? q.size() - i - 1 : i;
                ans.back().push_back(q[j]->val);
            }
            
            vector<TreeNode*> p;
            for (auto node : q) {
                if (node->left) p.push_back(node->left);
                if (node->right) p.push_back(node->right);
            }
            r = !r;
            q = p;
        }
        return ans;
    }
};