// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

// Runtime: 680 ms, faster than 61.66% of C++ online submissions for Minimum Number of Operations to Sort a Binary Tree by Level.
// Memory Usage: 120.3 MB, less than 93.89% of C++ online submissions for Minimum Number of Operations to Sort a Binary Tree by Level.

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
public:
    int minimumOperations(TreeNode *root)
    {
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size(), i = 0;
            vector<int> vals(n), idxs(n);
            while (i < n)
            {
                vals[i] = q.front()->val;
                idxs[i] = i;
                ++i;

                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }

            sort(idxs.begin(), idxs.end(), [&](int i, int j)
                 { return vals[i] < vals[j]; });
            for (i = 0; i < n; ++i)
                while (idxs[i] != i)
                    swap(idxs[i], idxs[idxs[i]]), ++res;
        }
        return res;
    }
};