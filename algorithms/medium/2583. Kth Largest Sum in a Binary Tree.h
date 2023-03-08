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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;

        queue<TreeNode*> l;
        l.push(root);

        while (!l.empty()) {
            auto size = l.size();
            long long sum = 0;
            while (size--) {
                auto node = l.front();
                l.pop();
                if (node->left) l.push(node->left);
                if (node->right) l.push(node->right);
                sum += node->val;
            }

            if (q.size() < k || q.top() < sum) q.push(sum);
            if (q.size() > k) q.pop();
        }

        return q.size() == k ? q.top() : -1;
    }
};