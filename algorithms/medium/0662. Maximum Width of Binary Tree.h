// 662. Maximum Width of Binary Tree

// Runtime: 4 ms, faster than 90.19% of C++ online submissions for Maximum Width of Binary Tree.
// Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Maximum Width of Binary Tree.

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
    int widthOfBinaryTree(TreeNode* root) {
        //    k    
        //   / \       
        // 2k  2k+1   
        if (!root) return 0;
        
        deque<uint64_t> keys;
        keys.push_back(0);
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        
        int ans = 0;
        while (!keys.empty()) {
            ans = max(ans, (int)(keys.back() - keys.front() + 1));
            auto size = keys.size();
            while (size--) {
                auto key = keys.front();
                keys.pop_front();
                auto node = nodes.front();
                nodes.pop_front();
                
                if (node->left) {
                    keys.push_back(key * 2);
                    nodes.push_back(node->left);
                }
                
                if (node->right) {
                    keys.push_back(key * 2 + 1);
                    nodes.push_back(node->right);
                }
            }
        }
        return ans;
    }
};