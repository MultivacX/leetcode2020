// 889. Construct Binary Tree from Preorder and Postorder Traversal

// Runtime: 16 ms, faster than 40.63% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
// Memory Usage: 15.1 MB, less than 16.67% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, 0, pre.size(), post, 0, post.size());
    }
    
    TreeNode* construct(vector<int>& pre, int pre_begin, int pre_end, vector<int>& pst, int pst_begin, int pst_end) {
        if (pre_begin >= pre_end) return nullptr;
        
        // pre[pre_begin] == pst[pst_end]
        auto root = new TreeNode(pre[pre_begin]);
        if (pre_end == pre_begin + 1) return root;
        
        // pre : [root][L ...][R ...]
        // pst : [... L][... R][root]
        
        if (pre[pre_begin + 1] != pst[pst_end - 2]) {
            // pre_L != pst_R
            int pre_left_begin = pre_begin + 1;
            int pre_left_end = pre_end; // pre_right_begin
            for (int i = pre_left_begin; i < pre_end; ++i) {
                if (pre[i] == pst[pst_end - 2]) {
                    pre_left_end = i;
                    break;
                }
            }
            int pre_right_begin = pre_left_end;
            int pre_right_end = pre_end;
            
            root->left  = construct(pre, pre_left_begin,  pre_left_end,  pst, pst_begin, pst_begin + (pre_left_end - pre_left_begin));
            root->right = construct(pre, pre_right_begin, pre_right_end, pst, pst_begin + (pre_left_end - pre_left_begin), pst_end - 1);
        } else {
            // pre_R == pst_R
            root->right = construct(pre, pre_begin + 1, pre_end, pst, pst_begin, pst_end - 1);
        }
        
        return root;
    }
};