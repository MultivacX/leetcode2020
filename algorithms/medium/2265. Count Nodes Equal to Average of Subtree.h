// 2265. Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

// Runtime: 13 ms, faster than 54.89% of C++ online submissions for Count Nodes Equal to Average of Subtree.
// Memory Usage: 12 MB, less than 42.63% of C++ online submissions for Count Nodes Equal to Average of Subtree.

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
class Solution
{
    int res = 0;

    pair<int, int> postOrder(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        auto l = postOrder(root->left);
        auto r = postOrder(root->right);

        int sum = l.first + root->val + r.first;
        int cnt = l.second + 1 + r.second;
        if (sum / cnt == root->val)
            ++res;
        return {sum, cnt};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        postOrder(root);
        return res;
    }
};