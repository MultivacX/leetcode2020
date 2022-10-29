// 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

// Runtime: 458 ms, faster than 85.29% of C++ online submissions for Amount of Time for Binary Tree to Be Infected.
// Memory Usage: 90.2 MB, less than 99.83% of C++ online submissions for Amount of Time for Binary Tree to Be Infected.

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
    int _start;
    int _res;

    int infectedRoot(TreeNode *node)
    {
        if (!node)
            return 0;
        if (node->val == _start)
        {
            return 1;
        }
        else
        {
            int l = infectedRoot(node->left);
            int r = infectedRoot(node->right);
            int v = l + r;
            if (v)
            {
                v += 1;
                node->val = 0;
            }
            return v;
        }
    }

    void f(TreeNode *node, int nodeTime)
    {
        if (!node)
            return;

        if (node->val == _start)
            nodeTime = 0;
        else if (node->val == 0)
            nodeTime -= 2;

        _res = max(_res, nodeTime);

        f(node->left, nodeTime + 1);
        f(node->right, nodeTime + 1);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        _start = start;
        _res = infectedRoot(root) - 1;
        root->val = -1;
        f(root, _res);
        return _res;
    }
};

// runtime error: signed integer overflow: 2148 * 1000000 cannot be represented in type 'int' (solution.cpp)
class Solution
{
    static const int m = 1000000;

    int findStart(TreeNode *node, int start)
    {
        if (!node)
            return 0;
        if (node->val == start)
        {
            node->val += 1 * m;
            return 1;
        }
        else
        {
            int l = findStart(node->left, start);
            int r = findStart(node->right, start);
            int v = l + r;
            if (v)
            {
                v += 1;
                node->val += v * m; // signed integer overflow
            }
            return v;
        }
    }

    int res = 0;

    void f(TreeNode *node, int pv)
    {
        if (!node)
            return;

        int v = node->val / m;
        if (v == 0)
            v = pv + 1;
        res = max(res, v);

        f(node->left, v);
        f(node->right, v);
    }

    // void print(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int s = q.size();
    //         while (s--) {
    //             auto n = q.front();
    //             q.pop();
    //             if (n->left) q.push(n->left);
    //             if (n->right) q.push(n->right);
    //             cout << n->val % m << '(' << n->val / m << ')' << ' ';
    //         }
    //         cout << endl;
    //     }
    // }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        findStart(root, start);
        // print(root);
        f(root, 0);
        return res - 1;
    }
};