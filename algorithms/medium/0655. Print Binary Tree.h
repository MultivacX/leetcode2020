// 655. Print Binary Tree

// Runtime: 4 ms, faster than 70.36% of C++ online submissions for Print Binary Tree.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Print Binary Tree.

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
    vector<vector<string>> printTree(TreeNode* root) {
        if (!root) return {};
        int ROWS = getLevels(root);
        int COLS = (1 << ROWS) - 1;
        vector<vector<string>> ans(ROWS, vector<string>(COLS, ""));
        int row = 0;
        int begin = 0;
        int end = COLS;
        deque<tuple<TreeNode*, int, int, int>> q;
        q.push_back({root, row, begin, end});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = get<0>(q.front());
                int row = get<1>(q.front());
                int begin = get<2>(q.front());
                int end = get<3>(q.front());
                q.pop_front();
                
                int mid = begin + (end - begin) / 2;
                ans[row][mid] = to_string(node->val);
                if (node->left) q.push_back({node->left, row + 1, begin, mid});
                if (node->right) q.push_back({node->right, row + 1, mid + 1, end});
            }
        }
        return ans;
    }
    
    int getLevels(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getLevels(root->left), getLevels(root->right));
    }
};