// 2326. Spiral Matrix IV
// https://leetcode.com/problems/spiral-matrix-iv/

// Runtime: 314 ms, faster than 78.30% of C++ online submissions for Spiral Matrix IV.
// Memory Usage: 127.8 MB, less than 76.27% of C++ online submissions for Spiral Matrix IV.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> res(m, vector<int>(n, -1));
        auto p = head;
        int r = 0, c = 0, i, j;
        while (p)
        {
            for (i = r, j = c; j <= n - 1 && p; ++j)
            {
                res[i][j] = p->val;
                p = p->next;
            }

            for (i = r + 1, j = n - 1; i <= m - 2 && p; ++i)
            {
                res[i][j] = p->val;
                p = p->next;
            }

            for (i = m - 1, j = n - 1; j >= c && p; --j)
            {
                res[i][j] = p->val;
                p = p->next;
            }

            for (i = m - 2, j = c; i >= r + 1 && p; --i)
            {
                res[i][j] = p->val;
                p = p->next;
            }

            ++r, ++c, --m, --n;
        }
        return res;
    }
};