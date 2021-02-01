// 776. Split BST
// Runtime: 4 ms, faster than 54.17% of C++ online submissions for Split BST.
// Memory Usage: 8.7 MB, less than 65.97% of C++ online submissions for Split BST.
    
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {nullptr, nullptr};
        
        if (root->val <= V) {
            auto p = splitBST(root->right, V);
            root->right = p[0];
            return {root, p[1]};
        } else {
            auto p = splitBST(root->left, V);
            root->left = p[1];
            return {p[0], root};
        }
    }
};

// Swift
// Runtime Error : if V < min(root)
/*
[4,2,6,1,3,5,7]
-20
class Solution {
    func splitBST(_ root: TreeNode?, _ V: Int) -> [TreeNode?] {
        if root == nil { return [nil, nil] }
        
        let node = root!
        if node.val <= V {
            let p = splitBST(node.right, V)
            node.right = p[0]
            return [node, p[1]]
        } else {
            let p = splitBST(node.left, V)
            node.left = p[1]
            return [p[0], node]
        }
    }
}
*/