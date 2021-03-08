// 222. Count Complete Tree Nodes

// Runtime: 36 ms, faster than 53.61% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 28.9 MB, less than 27.78% of C++ online submissions for Count Complete Tree Nodes.

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
    int countNodes(TreeNode* root) {
        return countNodes(root, -1, 1);
    }
    
    int getLevel(TreeNode* node, bool left) {
        int level = 0;
        while (node) {
            ++level;
            node = left ? node->left : node->right;
        }
        return level;
    }
    
    int countNodes(TreeNode* root, int leftLevel, int rightLevel) {
        if (!root) return 0;
        
        if (leftLevel < 0) leftLevel = getLevel(root, true);
        if (rightLevel < 0) rightLevel = getLevel(root, false);
        
        if (leftLevel == rightLevel) return (2 << (leftLevel - 1)) - 1;
        
        return 
            countNodes(root->left, leftLevel - 1, -1) + // root->left
            1 + // root
            countNodes(root->right, -1, rightLevel - 1); // root->right
    }
};


class Solution {
    int getLevels(TreeNode* root, bool toLeft) {
        if (!root) return 0;
        return 1 + getLevels(toLeft ? root->left : root->right, toLeft);
    }
    
public:
    int countNodes(TreeNode* root, int preToLeft = -1) {
        if (!root) return 0;
        
        int toLeft = preToLeft < 0 ? getLevels(root, true) : preToLeft;
        int toRight = getLevels(root, false);
        if (toLeft == toRight)
            return (1 << toLeft) - 1;
        
        return 1 + countNodes(root->left, toLeft - 1) + countNodes(root->right);
    }
};